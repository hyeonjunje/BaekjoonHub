#include<iostream>
#include<vector>
#include<algorithm>

#define MAXLOG 18
#define MAX 100001
using namespace std;

vector<pair<int, int>> tree[MAX]{};  //<목적지, 거리>
pair<int, pair<int, int>> parent[MAX][MAXLOG]{};
bool visited[MAX]{};
int Rank[MAX];

void dfs(int current)
{
	visited[current] = true;

	for (int i = 0; i < tree[current].size(); i++)
	{
		pair<int, int> next = tree[current][i];
		if (visited[next.first] == false)
		{
			Rank[next.first] = Rank[current] + 1;
			parent[next.first][0].first = current;
			parent[next.first][0].second = { next.second, next.second };
			dfs(next.first);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, A, B, C, K, D, E;

	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> A >> B >> C;
		tree[A].push_back({ B, C });
		tree[B].push_back({ A, C });
	}
	
	// 1을 root로 잡음
	dfs(1);

	for (int i = 1; i <= MAXLOG - 1; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			parent[j][i].first = parent[parent[j][i - 1].first][i - 1].first;
			if (parent[j][i].first != 0)
			{
				parent[j][i].second.first = max(parent[j][i - 1].second.first, parent[parent[j][i - 1].first][i - 1].second.first);
				parent[j][i].second.second = min(parent[j][i - 1].second.second, parent[parent[j][i - 1].first][i - 1].second.second);
			}
		}
	}

	/*for (int j = 1; j <= N; j++)
	{
		cout << j << " 노드입니다. ";
		for (int i = 0; i <= MAXLOG - 1; i++)
		{
			cout << parent[j][i].second.first << ' ';
		}
		cout << '\n';
	}*/

	cin >> K;
	while (K--)
	{
		int maxV = 0;
		int minV = 1000000;

		cin >> D >> E;

		while (Rank[D] != Rank[E])
		{
			if (Rank[D] < Rank[E])
			{
				int diff = Rank[E] - Rank[D];
				for (int i = 0; diff; i++)
				{
					if (diff % 2 == 1) 
					{ 
						maxV = max(maxV, parent[E][i].second.first);
						minV = min(minV, parent[E][i].second.second);
						E = parent[E][i].first; 
					}
					diff >>= 1;
				}
			}
			else
			{
				int diff = Rank[D] - Rank[E];
				for (int i = 0; diff; i++)
				{
					if (diff % 2 == 1)
					{
						maxV = max(maxV, parent[D][i].second.first);
						minV = min(minV, parent[D][i].second.second);
						D = parent[D][i].first;
					}
					diff >>= 1;
				}
			}
		}

		if (D != E)
		{
			for (int i = MAXLOG - 1; i >= 0; i--)
			{
				if (parent[D][i].first != 0 && parent[D][i].first != parent[E][i].first)
				{
					maxV = max(maxV, max(parent[D][i].second.first, parent[E][i].second.first));
					minV = min(minV, min(parent[D][i].second.second, parent[E][i].second.second));

					D = parent[D][i].first;
					E = parent[E][i].first;
				}
			}
			maxV = max(maxV, max(parent[D][0].second.first, parent[E][0].second.first));
			minV = min(minV, min(parent[D][0].second.second, parent[E][0].second.second));
			D = parent[D][0].first;
		}
		cout << minV << ' ' << maxV << '\n';
	}
}