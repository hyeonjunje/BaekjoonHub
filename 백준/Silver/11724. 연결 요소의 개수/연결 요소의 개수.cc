#include<iostream>
#include<vector>
using namespace std;

#define MAX 1001
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int current)
{
	visited[current] = true;

	for (int next : graph[current])
	{
		if (visited[next] == false)
		{
			dfs(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 0)
		{
			dfs(i);
			ans++;
		}
	}
	cout << ans;
}