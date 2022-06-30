#include<iostream>

#define MAX 1000000003
using namespace std;

int dp[1001][1001]{};

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K;

	cin >> N >> K;

	for (int i = 0; i <= N; i++)
	{
		dp[i][1] = i;
		dp[i][0] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= K; j++)
		{
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MAX;

			if (i == N && j == K) dp[i][j] = (dp[i - 1][j] + dp[i - 3][j - 1]) % MAX;
		}
	}
	cout << dp[N][K];
}