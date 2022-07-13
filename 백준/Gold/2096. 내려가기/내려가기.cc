#include<iostream>
#include<algorithm>

using namespace std;

int dp[5][3];  // 0 최소, 1 최대, 2 이전 최소, 3 이전 최대, 4 현재

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> dp[4][0] >> dp[4][1] >> dp[4][2];

		dp[1][0] = dp[4][0] + max(dp[3][0], dp[3][1]);
		dp[1][1] = dp[4][1] + max(dp[3][0], max(dp[3][1], dp[3][2]));
		dp[1][2] = dp[4][2] + max(dp[3][1], dp[3][2]);

		for (int i = 0; i < 3; i++)
		{
			dp[3][i] = dp[1][i];
		}

		dp[0][0] = dp[4][0] + min(dp[2][0], dp[2][1]);
		dp[0][1] = dp[4][1] + min(dp[2][0], min(dp[2][1], dp[2][2]));
		dp[0][2] = dp[4][2] + min(dp[2][1], dp[2][2]);

		for (int i = 0; i < 3; i++)
		{
			dp[2][i] = dp[0][i];
		}
	}
	cout << *max_element(dp[1], dp[1] + 3) << ' ' << *min_element(dp[0], dp[0] + 3);
}