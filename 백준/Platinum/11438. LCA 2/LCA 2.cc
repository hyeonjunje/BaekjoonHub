#include<iostream>
#include<vector>

using namespace std;

#define MAX 100001
#define MAXLOG 18

int N, a, b, M;
vector<int> tree[100001]{};
int parent[MAXLOG][MAX]{};
int depth[MAX]{};

void dfs(int current)
{
	for (int i = 0; i < tree[current].size(); i++)
	{
		int next = tree[current][i];
		if (depth[next] == -1)
		{
			depth[next] = depth[current] + 1;
			parent[0][next] = current;
			dfs(next);
		}
	}
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	for (int i = 2; i <= N; i++)
	{
		depth[i] = -1;
	}

	dfs(1);

	for (int i = 0; i < MAXLOG - 1; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			parent[i + 1][j] = parent[i][parent[i][j]];
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;

		// 항상 a가 더 밑에 있는 경우라고 생각
		if (depth[a] < depth[b]) swap(a, b);
		int diff = depth[a] - depth[b];

		for (int j = 0; diff; j++)
		{
			if (diff % 2 == 1)
				a = parent[j][a];

			diff >>= 1;
		}

		if (a != b)
		{
			for (int i = MAXLOG - 1; i >= 0; i--)
			{
				if (parent[i][a] != 0 && parent[i][a] != parent[i][b])
				{
					a = parent[i][a];
					b = parent[i][b];
				}
			}
			cout << parent[0][a] << '\n';
		}
		else
		{
			cout << a << '\n';
		}
	}
}