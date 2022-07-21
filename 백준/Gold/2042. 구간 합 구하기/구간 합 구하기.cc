#include<iostream>
#include<cmath>

#define MAX 1000001
using namespace std;

long long* tree;
long long a[MAX];

long long init(int start, int end, int node)
{
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;

	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right)
{
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int from, long long diff)
{
	if (from < start || from > end) return;
	tree[node] += diff;
	if (start == end) return;

	int mid = (start + end) / 2;

	update(start, mid, node * 2, from, diff);
	update(mid + 1, end, node * 2 + 1, from, diff);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;
	int height = (int)ceil(log2(N));
	tree = new long long[1 << (height + 1)];

	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
	}
	
	init(1, N, 1);

	for (int i = 0; i < M + K; i++)
	{
		int n1, n2;
		long long n3;
		cin >> n1 >> n2 >> n3;
		if (n1 == 1)
		{
			long long diff = n3 - a[n2];
			a[n2] = n3;
			update(1, N, 1, n2, diff);
		}
		else if(n1 == 2)
		{
			cout << sum(1, N, 1, n2, n3) << '\n';
		}
	}
}

