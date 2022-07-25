#include<iostream>
#include<string>
#define MAX 100001
using namespace std;

int N, M, flag, ai, aj, k, ax;
long long ans = 0;

long long nums[MAX];
long long tree[MAX * 4];

void update(int start, int end, int node, int left, int right, int val)
{
	if (right < start || end < left) return;
	if (left <= start && end <= right) { tree[node] += val; return; }

	int mid = (start + end) / 2;

	update(start, mid, node * 2, left, right, val);
	update(mid + 1, end, node * 2 + 1, left, right, val);
}

void findAns(int start, int end, int node, int idx)
{
	if (idx < start || end < idx) return;

	if (start == end)
	{
		ans += tree[node];
		return;
	}

	ans += tree[node];
	int mid = (start + end) / 2;
	findAns(start, mid, node * 2, idx);
	findAns(mid + 1, end, node * 2 + 1, idx);

}
	

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> nums[i];
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> flag;
		if (flag == 1)
		{
			cin >> ai >> aj >> k;
			update(1, N, 1, ai, aj, k);
		}
		else
		{
			cin >> ax;
			ans = 0;
			findAns(1, N, 1, ax);
			cout << nums[ax] + ans << '\n';
		}
	}
}