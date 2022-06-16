#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 10001

vector<int> graph[MAX];
int num[MAX];
bool visited[MAX];

int dp[MAX][2]; // 0 : 우수마을 X,  1 : 우수마을 O 

void dfs(int start)
{
	visited[start] = true;

	dp[start][1] = num[start];

	for (int i = 0; i < graph[start].size(); i++)
	{
		int next = graph[start][i];
		if (visited[next]) continue;

		dfs(next);

		dp[start][0] += max(dp[next][0], dp[next][1]);
		dp[start][1] += dp[next][0];
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, a, b;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> num[i];

	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);
	cout << max(dp[1][0], dp[1][1]);
}