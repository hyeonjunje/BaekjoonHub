#include<iostream>

#define MAX 100001
using namespace std;

long long nums[MAX];
long long minTree[4 * MAX];
long long maxTree[4 * MAX];

int N, M, a, b;


long long init(int start, int end, int node)
{
	if (start == end) 
	{
		return minTree[node] = nums[start];
	}
	int mid = (start + end) / 2;

	return minTree[node] =
	{
		min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1))
	};
}

long long findMinMax(int start, int end, int node, int left, int right)
{
	if (end < left || right < start) return 1000000001;
	if (left <= start && end <= right) return minTree[node];

	int mid = (start + end) / 2;

	return
	{
		min(findMinMax(start, mid, node * 2, left, right), findMinMax(mid + 1, end, node * 2 + 1, left, right)),
	};
}

long long init1(int start, int end, int node)
{
	if (start == end)
	{
		return maxTree[node] = nums[start];
	}
	int mid = (start + end) / 2;

	return maxTree[node] =
	{
		max(init1(start, mid, node * 2), init1(mid + 1, end, node * 2 + 1))
	};
}

long long findMinMax1(int start, int end, int node, int left, int right)
{
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) return maxTree[node];

	int mid = (start + end) / 2;

	return
	{
		max(findMinMax1(start, mid, node * 2, left, right), findMinMax1(mid + 1, end, node * 2 + 1, left, right)),
	};
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> nums[i];
	}

	init(1, N, 1);
	init1(1, N, 1);

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		cout << findMinMax(1, N, 1, a, b) << ' ' << findMinMax1(1, N, 1, a, b) << '\n';
	}
}