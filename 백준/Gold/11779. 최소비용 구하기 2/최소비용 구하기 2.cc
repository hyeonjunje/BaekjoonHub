#include<iostream>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;

int MAX = 2000000000;
int startNum, endNum;
vector<pair<int, int>> graph[1001]{};
pair < int, vector<int >> visited[1001]{};


void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;  // 노드, 비용
	pq.push({ start, 0 });
	visited[start] = { 0, {start} };

	while (!pq.empty())
	{
		int current = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();

		if (visited[current].first < cost) continue;

		for (int i = 0; i < graph[current].size(); i++)
		{
			int nextNode = graph[current][i].first;
			int nextCost = graph[current][i].second + cost;

			if (visited[nextNode].first > nextCost)
			{
				visited[nextNode].first = nextCost;
				visited[nextNode].second = visited[current].second;
				visited[nextNode].second.push_back(nextNode);

				pq.push({ nextNode, -nextCost });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m, a, b, c;

	for (int i = 0; i < 1001; i++)
	{
		visited[i].first = MAX;
	}

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;

		graph[a].push_back({ b, c });
	}
	cin >> startNum >> endNum;
	dijkstra(startNum);

	cout << visited[endNum].first << '\n' << visited[endNum].second.size() << '\n';

	for (int i = 0; i < visited[endNum].second.size(); i++)
	{
		cout << visited[endNum].second[i] << ' ';
	}
}