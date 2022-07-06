#include<iostream>

using namespace std;

int parent[10001];
int root = 0;
int Rank = 1;
int findRank(int root, int current)
{
	if (root == current) return Rank;
	Rank++;
	return findRank(root, parent[current]);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T, N, A, B;
	cin >> T;
	while (T--)
	{
		cin >> N;

		// 초기화
		for (int i = 1; i <= N; i++) parent[i] = -1;

		for (int i = 0; i < N - 1; i++)
		{
			cin >> A >> B;
			parent[B] = A;
		}

		for (int i = 1; i <= N; i++)
			if (parent[i] == -1)
				root = i;
		

		cin >> A >> B;

		Rank = 1;
		int rankA = findRank(root, A);
		Rank = 1;
		int rankB = findRank(root, B);

		while (rankA != rankB)
		{
			if (rankA > rankB)
			{
				A = parent[A];
				rankA--;
			}
			else if (rankA < rankB)
			{
				B = parent[B];
				rankB--;
			}
		}

		while (A != B)
		{
			A = parent[A];
			B = parent[B];
		}
		cout << A << '\n';
	}
}