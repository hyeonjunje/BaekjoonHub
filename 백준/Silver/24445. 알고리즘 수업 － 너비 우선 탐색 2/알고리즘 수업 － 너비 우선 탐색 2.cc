#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

bool visited[100001]{};
int visitOrder[100001]{};
vector<int> graph[100001]{};
int order = 1;
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	visitOrder[start] = order++;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int node : graph[cur])
		{
			if (visited[node] == false)
			{
				visited[node] = true;
				visitOrder[node] = order++;
				q.push(node);
			}
		}
	}
}

bool com(int a, int b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, R, u, v;
	cin >> N >> M >> R;

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end(), com);
	}

	bfs(R);

	for (int i = 1; i <= N; i++)
	{
		cout << visitOrder[i] << '\n';
	}
}