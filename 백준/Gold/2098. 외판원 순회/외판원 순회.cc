#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>

using namespace std;

#define MAX 2000000000;

int N;
int dp[16][1 << 16];
int w[16][16];


int dfs(int current, int bit)
{
	if (bit == (1 << N) - 1)
	{
		if (w[current][0] == 0) return MAX;
		return w[current][0];
	}

	if (dp[current][bit] != -1) return dp[current][bit];
	dp[current][bit] = MAX;

	for (int i = 0; i < N; i++)
	{
		if (w[current][i] == 0) continue;
		if (!(bit & 1 << i))
			dp[current][bit] = min(dp[current][bit], w[current][i] + dfs(i, bit | 1 << i));
	}
	return dp[current][bit];
	
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> w[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 1);

}