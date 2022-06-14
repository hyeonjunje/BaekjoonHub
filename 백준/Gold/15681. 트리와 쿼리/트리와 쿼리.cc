#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

vector<int> graph[100001]{};

int cache[100001]{};
bool visited[100001]{};

int dfs(int start)
{
	visited[start] = true;

	for (int i = 0; i < graph[start].size(); i++)
	{
		if (visited[graph[start][i]] == false)
		{
			cache[start] += dfs(graph[start][i]);
		}
	}
	return cache[start];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, R, Q, a, b;
	cin >> N >> R >> Q;
	for (int i = 1; i <= N; i++) cache[i] = 1;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(R);

	for (int i = 0; i < Q; i++)
	{
		cin >> a;
		cout << cache[a] << '\n';
	}
}
