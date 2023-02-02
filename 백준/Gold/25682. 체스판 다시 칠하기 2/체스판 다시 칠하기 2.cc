#include<iostream>
#include<algorithm>

using namespace std;

char chess[2001][2001];
int dp[2001][2001];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, M, K;
	int result = 5000000;
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> chess[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int distance = i + j;

			if (distance % 2 == 0 && chess[i][j] == 'B')
				dp[i][j] = 1;
			else if (distance % 2 == 1 && chess[i][j] == 'W')
				dp[i][j] = 1;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	for (int i = K; i <= N; i++)
	{
		for (int j = K; j <= M; j++)
		{
			int val = dp[i][j] - dp[i - K][j] - dp[i][j - K] + dp[i - K][j - K];
			result = min({ result, val, K * K - val });
		}
	}

	cout << result;
}