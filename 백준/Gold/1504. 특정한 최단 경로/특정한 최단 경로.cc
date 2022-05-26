#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<pair<int, int>> graph[801];
int INF = 200000000;
int N, E;
int dist[801]{};

void dijkstra(int start)
{
	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
	}
	dist[start] = 0;
	priority_queue<pair<int, int>> pq; 
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();

		// 최단거리가 아닐경우 스킵
		if (dist[current] < distance) continue;

		for (int i = 0; i < graph[current].size(); i++)
		{
			int next = graph[current][i].first;
			int nextDistance = distance + graph[current][i].second;

			if (nextDistance < dist[next])
			{
				dist[next] = nextDistance;
				pq.push({ next, -nextDistance });
			}
		}
	}


}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b, c, u, v;

	cin >> N >> E;

	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	cin >> u >> v;

	dijkstra(1);
	int routine1 = dist[u];
	int routine2 = dist[v];
	dijkstra(u);
	routine1 += dist[v];
	dijkstra(v);
	routine1 += dist[N];

	dijkstra(v);
	routine2 += dist[u];
	dijkstra(u);
	routine2 += dist[N];

	cout << (min(routine1, routine2) >= INF ? -1 : min(routine1, routine2));
}