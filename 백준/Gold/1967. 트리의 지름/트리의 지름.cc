#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

vector<pair<int, int>> graph[10001]{};
int dist[10001];

int fallAwayPoint;
int maxDistance = 0;

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty())
	{
		int current = pq.top().first;
		int curDist = -pq.top().second;
		pq.pop();

		if (curDist < dist[current]) continue;

		for (int i = 0; i < graph[current].size(); i++)
		{
			if (dist[graph[current][i].first] == -1)
			{
				int next = graph[current][i].first;
				int nextDist = graph[current][i].second + curDist;

				if (dist[next] < nextDist)
				{
					if (maxDistance < nextDist)
					{
						maxDistance = nextDist;
						fallAwayPoint = next;
					}
					dist[next] = nextDist;

					pq.push({ next, -nextDist });
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	memset(dist, -1, sizeof(dist));

	int n, a, b, c;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	dijkstra(1);
	
	memset(dist, -1, sizeof(dist));
	maxDistance = 0;
	dijkstra(fallAwayPoint);

	cout << dist[fallAwayPoint];
}