#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAX 1000001

vector<int> graph[MAX];
bool visited[MAX];
int dp[MAX][2];


void dfs(int start)
{
	visited[start] = true;
	dp[start][0] = 1;
	vector<int> child;
	for (int i = 0; i < graph[start].size(); i++)
	{
		int next = graph[start][i];
		if (visited[next]) continue;

		dfs(next);
		dp[start][1] += dp[next][0];
		dp[start][0] += min(dp[next][0], dp[next][1]);

	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, a, b;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);

	cout << min(dp[1][0], dp[1][1]);
}