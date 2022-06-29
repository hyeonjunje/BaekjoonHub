#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;


int N;
int dp[1001][3];
int w[1001][3];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int color = 0; color < 3; color++)
		{
			cin >> w[i][color];
		}
	}

	int ans = 1000001;


	for (int color = 0; color < 3; color++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == color) dp[0][i] = w[0][i];
			else dp[0][i] = 1000000;
		}

		for (int i = 1; i < N; i++)
		{
			dp[i][0] = w[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = w[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = w[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}

		for (int i = 0; i < 3; i++)
		{
			if (i != color)
			{
				ans = min(ans, dp[N - 1][i]);
			}
		}
	}

	cout << ans;
}