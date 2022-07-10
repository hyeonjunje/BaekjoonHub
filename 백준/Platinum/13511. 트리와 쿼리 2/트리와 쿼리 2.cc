#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

#define MAX 100010
#define MAXLOG 18

vector<pair<int, int>> graph[MAX]{};

int parent[MAXLOG][MAX];  // 지수로 올라가는 정점
int Rank[MAX]{};
long long Cost[MAX]{};

void dfs(int current)
{
	for (int i = 0; i < graph[current].size(); i++)
	{
		pair<int, int> next = graph[current][i];
		if (Rank[next.first] == -1)
		{
			Cost[next.first] = Cost[current] + next.second;
			Rank[next.first] = Rank[current] + 1;
			parent[0][next.first] = current;
			dfs(next.first);
		}
	}
}

int LCA(int b, int c)
{
	if (Rank[b] < Rank[c])
	{
		int diff = Rank[c] - Rank[b];
		for (int i = 0; diff; i++)
		{
			if (diff % 2 == 1) { c = parent[i][c]; }
			diff >>= 1;
		}
	}
	else
	{
		int diff = Rank[b] - Rank[c];
		for (int i = 0; diff; i++)
		{
			if (diff % 2 == 1) { b = parent[i][b]; }
			diff >>= 1;
		}
	}

	if (b != c)
	{
		for (int i = MAXLOG - 1; i >= 0; i--)
		{
			if (parent[i][b] != 0 && parent[i][b] != parent[i][c])
			{
				b = parent[i][b];
				c = parent[i][c];
			}
		}
		b = parent[0][b];
		c = parent[0][c];
	}
	return b;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	memset(Rank, -1, sizeof(Rank));
	int N, u, v, w, M, a, b, c, d;
	cin >> N;
	
	for(int i = 0; i < N - 1; i++)
	{
		cin >> u >> v >> w;

		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}

	Rank[1] = 0;
	dfs(1);

	for (int i = 1; i <= MAXLOG - 1; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}

	//for (int i = 1; i <= N; i++)
	//{
	//	for (int j = 0; j < MAXLOG - 1; j++)
	//	{
	//		cout << parent[j][i].second << ' ';
	//	}
	//	cout << '\n';
	//}


	cin >> M;
	while (M--)
	{
		
		cin >> a >> b >> c;
		long long distance = Cost[b] + Cost[c];
		int lca = LCA(b, c);
		distance -= 2 * Cost[lca];


		if(a == 1)
			cout << distance << '\n';
		else
		{
			cin >> d;

			int vertaxCountb = Rank[b] - Rank[lca] + 1;



			if (vertaxCountb == d) cout << lca << '\n';
			else if (vertaxCountb < d)
			{
				d -= vertaxCountb;
				d = Rank[c] - Rank[lca] - d;

				for (int i = 0; d; i++)
				{
					if (d % 2) c = parent[i][c];
					d >>= 1;
				}
				cout << c << '\n';
			}
			else
			{
				d--;
				for (int i = 0; d; i++)
				{
					if (d % 2) b = parent[i][b];
					d >>= 1;
				}
				cout << b << '\n';
			}
		}
	}
}