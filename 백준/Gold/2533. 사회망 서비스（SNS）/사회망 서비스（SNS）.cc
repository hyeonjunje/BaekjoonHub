#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

#define MAX 1000001

vector<int> graph[MAX];
bool visited[MAX];
int dp[MAX];

bool checkEqual(vector<int> child)
{
	for (int i : child)
	{
		if (dp[i] == -1) return true;
	}
	return false;
}

void dfs(int start)
{
	visited[start] = true;
	vector<int> child;
	for (int i = 0; i < graph[start].size(); i++)
	{
		int next = graph[start][i];
		if (!visited[next])
		{
			dfs(next);
			child.push_back(next);
		}
	}

	if (checkEqual(child))
	{
		dp[start] = 1;
	}
	
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, a, b;
	cin >> N;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (dp[i] == 1) ans++;
	}
	cout << ans;
}