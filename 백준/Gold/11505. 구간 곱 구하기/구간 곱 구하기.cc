#include<iostream>

#define MAX 1000001
#define MOD 1000000007

using namespace std;

long long tree[MAX * 4];
long long nums[MAX];

int N, M, K, a, b;
long long c;

long long init(int start, int end, int node)
{
	if (start == end) return tree[node] = nums[start];

	int mid = (start + end) / 2;

	return tree[node] = (init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1)) % MOD;
}

long long mul(int start, int end, int node, int left, int right)
{

	if (right < start || end < left) return 1;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;

	return (mul(start, mid, node * 2, left, right) * mul(mid + 1, end, node * 2 + 1, left, right)) % MOD;
}

long long update(int start, int end, int node, int idx, long long val)
{
	if (idx < start || idx > end) return tree[node];

	if (start == end) return tree[node] = val;

	int mid = (start + end) / 2;

	return tree[node] = (update(start, mid, node * 2, idx, val) * update(mid + 1, end, node * 2 + 1, idx, val)) % MOD;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> nums[i];
	}

	init(1, N, 1);
	
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			nums[b] = c;
			update(1, N, 1, b, c);
		}
		else
		{
			cout << mul(1, N, 1, b, c) << '\n';
		}
	}
}