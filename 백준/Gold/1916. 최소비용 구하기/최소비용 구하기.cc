#include<iostream>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;

#define MAX 100000000;

vector<pair<int, int>> graph[1001]{};
int dist[1001]{};
int start, dest;

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty())
	{
		int current = pq.top().first;
		int cost = -pq.top().second;

		pq.pop();

		//if (current == dest) return;

		if (cost > dist[current]) continue;

		for (int i = 0; i < graph[current].size(); i++)
		{
			int node = graph[current][i].first;
			int nextCost = cost + graph[current][i].second;

			if (nextCost < dist[node])
			{
				dist[node] = nextCost;
				pq.push({ node, -nextCost });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, a, b, c;

	cin >> N >> M;

	for (int i = 0; i <= N; i++) dist[i] = MAX;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}


	cin >> start >> dest;

	dijkstra(start);
	cout << dist[dest];
}