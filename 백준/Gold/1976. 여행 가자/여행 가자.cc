#include<iostream>
#include<vector>

using namespace std;

int root[201]{};
int Rank[201]{};

int Find(int x)
{
	if (root[x] == x) return x;

	return root[x] = Find(root[x]);
}

void Union(int a, int b)
{
	a = Find(a), b = Find(b);

	if (Rank[a] < Rank[b]) root[a] = b;
	else root[b] = a;

	if (Rank[a] == Rank[b]) Rank[a]++;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, city;
	cin >> N >> M;

	for (int i = 0; i <= N; i++)
	{
		root[i] = i;
		Rank[i] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> city;
			if (i == j) continue;
			if (city == 1) Union(i + 1, j+1);
		}
	}

	vector<int> v;
	for (int i = 0; i < M; i++)
	{
		cin >> city;
		v.push_back(city);
	}

	for (int i = 1; i < v.size(); i++)
	{
		if (root[v[0]] != root[v[i]]) { cout << "NO"; return 0; }
	}
	cout << "YES";
}
