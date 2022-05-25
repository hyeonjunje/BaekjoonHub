#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

bool visited[101];
int dist[101];
vector<int> graph[101];

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	dist[start] = 0;

	while (!q.empty())
	{
		int pos = q.front();
		q.pop();


		for (int i = 1; i <= 6; i++)
		{
			int nx = pos + i;
			if (nx > 100) continue;

			if (!graph[pos + i].empty())
			{
				nx = graph[pos + i][0];
			}
			if (dist[nx] == 10000)
			{
				//visited[nx] = true;
				dist[nx] = dist[pos] + 1;
				q.push(nx);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, x, y;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		graph[x].push_back(y);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		graph[x].push_back(y);
	}

	for (int i = 0; i <= 100; i++)
	{
		dist[i] = 10000;
	}

	bfs(1);

	cout << dist[100];
}