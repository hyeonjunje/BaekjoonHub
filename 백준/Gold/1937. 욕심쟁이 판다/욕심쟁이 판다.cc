#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

int dp[501][501];
int w[501][501];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool visited[501][501];

int N;

int dfs(int y, int x)
{
	// 상하좌우 확인하고 내가 제일 크면 1로 리턴
	bool flag = true;
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (nextX > 0 && nextX <= N && nextY > 0 && nextY <= N && w[y][x] < w[nextY][nextX])
			flag = false;
	}
	if (flag) dp[y][x] = 1;

	// 값이 이미 있으면 그 값을 리턴
	if (dp[y][x] != -1) return dp[y][x];

	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (nextX > 0 && nextX <= N && nextY > 0 && nextY <= N && w[y][x] < w[nextY][nextX])
		{
			dp[y][x] = max(dp[y][x], dfs(nextY, nextX) + 1);
		}
	}

	return dp[y][x];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> w[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			dfs(i, j);
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}