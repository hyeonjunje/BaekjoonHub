#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool visited[100001]{};
int visitOrder[100001]{};
vector<int> graph[100001]{};

int order = 1;

void dfs(int start)
{
	visited[start] = true;
	visitOrder[start] = order++;
	for (int node : graph[start])
	{
		if (visited[node] == false)
		{
			dfs(node);
		}
	}
	
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
		sort(graph[i].begin(), graph[i].end());

	dfs(R);

	for (int i = 1; i <= N; i++)
		cout << visitOrder[i] << '\n';
}