#include<iostream>
#include<vector>
#define MAX 2000001
using namespace std;

int N, T, X;

void update(vector<int>& tree, int start, int end, int node, int idx, int val)
{
	if (idx < start || end < idx) return;
	if (start == end) { tree[node] += val; return; }

	int mid = (start + end) / 2;

	update(tree, start, mid, node * 2, idx, val);
	update(tree, mid + 1, end, node * 2 + 1, idx, val);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int kth(vector<int>& tree, int start, int end, int node, int idx)
{
	if (start == end) return start;

	int mid = (start + end) / 2;

	if (idx <= tree[node * 2])
	{
		return kth(tree, start, mid, node * 2, idx);
	}
	else
	{
		return kth(tree, mid + 1, end, node * 2 + 1, idx - tree[node * 2]);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	vector<int> v(MAX * 4, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> T >> X;

		if (T == 1)
		{
			update(v, 1, MAX, 1, X, 1);
		}
		else
		{
			int pos = kth(v, 1, MAX, 1, X);
			update(v, 1, MAX, 1, pos, -1);
			cout << pos << '\n';
		}
	}
}