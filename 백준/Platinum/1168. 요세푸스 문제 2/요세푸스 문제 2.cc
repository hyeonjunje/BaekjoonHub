#include<iostream>
#define MAX 100001
using namespace std;

int tree[MAX * 4];
int nums[MAX];

void init(int start, int end, int node)
{
	if (start == end) { tree[node] = nums[start]; return; }

	int mid = (start + end) / 2;

	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int kth(int start, int end, int node, int idx)
{
	if (start == end) return start; 

	int mid = (start + end) / 2;

	if (idx <= tree[node * 2]) return kth(start, mid, node * 2, idx);
	else return kth(mid + 1, end, node * 2 + 1, idx - tree[node * 2]);
}

void update(int start, int end, int node, int idx, int val)
{
	if (idx < start || end < idx) return;
	if (start == end) { tree[node] += val; return; }

	int mid = (start + end) / 2;

	update(start, mid, node * 2, idx, val);
	update(mid + 1, end, node * 2 + 1, idx, val);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) nums[i] = 1;

	init(1, N, 1);
	
	int idx = 1;

	cout << "<";
	for (int i = 0; i < N; i++)
	{
		int size = N - i;
		idx += K - 1;

		if (idx % size == 0) idx = size;
		else if (idx > size) idx %= size;

		int pos = kth(1, N, 1, idx);
		cout << pos;
		update(1, N, 1, pos, -1);
		
		//size--;


		if (i != N - 1)
			cout << ", ";
	}
	cout << ">";
}