#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

int cost[10001]{};
int dp[2][10001]{}; // dp[0] : 노드 포함, dp[1] : 노드 포함X
vector<int> graph[10001]{};

bool visited[10001]{};
vector<int> path;


void dfs(int start)
{
	visited[start] = true;
	dp[0][start] = cost[start];
	dp[1][start] = 0;

	for (int i = 0; i < graph[start].size(); i++)
	{
		if (visited[graph[start][i]] == false)
		{
			dfs(graph[start][i]);
			dp[0][start] += dp[1][graph[start][i]];
			dp[1][start] += max(dp[1][graph[start][i]], dp[0][graph[start][i]]);
		}
	}
}

void tracking(int now, int prev)
{
	if (dp[0][now] > dp[1][now] && !visited[prev])
	{
		visited[now] = true;
		path.push_back(now);
	}

	for (int i = 0; i < graph[now].size(); i++)
	{
		int next = graph[now][i];
		if (next != prev)
		{
			tracking(next, now);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, a, b;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);
	memset(visited, false, sizeof(visited));
	tracking(1, 0);
	sort(path.begin(), path.end());

	cout << max(dp[0][1], dp[1][1]) << '\n';
	for (auto i : path) cout << i << ' ';

}