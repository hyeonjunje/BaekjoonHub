#include<iostream>
#define MAX 100001
using namespace std;

int T, N, K, Q, A, B;
int nums[MAX];
pair<int, int> tree[MAX * 4]; // 최소, 최대

pair<int, int> init(int start, int end, int node)
{
	if (start == end) return tree[node] = { nums[start], nums[start] };

	int mid = (start + end) / 2;

	pair<int, int> leftChild = init(start, mid, node * 2);
	pair<int, int> rightChild = init(mid + 1, end, node * 2 + 1);

	return tree[node] = { min(leftChild.first, rightChild.first), max(leftChild.second, rightChild.second) };
}

pair<int, int> getMinMax(int start, int end, int node, int left, int right)
{
	if (right < start || end < left) return { 100001, 0 };
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	pair<int, int> leftChild = getMinMax(start, mid, node * 2, left, right);
	pair<int, int> rightChild = getMinMax(mid + 1, end, node * 2 + 1, left, right);
	return { min(leftChild.first, rightChild.first), max(leftChild.second, rightChild.second) };
}

void Update(int start, int end, int node, int idx1, int idx2)
{
	if (idx1 < start || end < idx1) return;
	if (start == end) { tree[node] = { nums[idx2], nums[idx2] }; return; }
	int mid = (start + end) / 2;

	Update(start, mid, node * 2, idx1, idx2);
	Update(mid + 1, end, node * 2 + 1, idx1, idx2);

	tree[node] = { min(tree[node * 2].first, tree[node * 2 + 1].first), max(tree[node * 2].second, tree[node * 2 + 1].second) };
}



int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--)
	{
		cin >> N >> K;

		for (int i = 1; i <= N; i++)
		{
			nums[i] = i;
		}
		init(1, N, 1);

		for (int i = 1; i <= K; i++)
		{
			cin >> Q >> A >> B;
			A++;
			B++;
			if (Q == 0)
			{
				Update(1, N, 1, A, B);
				Update(1, N, 1, B, A);
				int temp = nums[A];
				nums[A] = nums[B];
				nums[B] = temp;
			}
			else if(Q == 1)
			{
				pair<int, int> minMax = getMinMax(1, N, 1, A, B);

				//cout << A << ' ' << B << ' ' << minMax.first << ' ' << minMax.second << '\n';

				if (minMax.first == A && minMax.second == B) cout << "YES" << '\n';
				else cout << "NO" << '\n';
			}
		}
	}
}