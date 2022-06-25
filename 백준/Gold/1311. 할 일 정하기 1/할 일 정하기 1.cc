#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int w[20][20]{};
int dp[1048577]{};

int countBit(int i)
{
	int ans = 0;

	while (i)
	{
		ans += (i & 1);
		i >>= 1;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> w[i][j];
		}

	for (int i = 0; i < pow(2, N); i++)
		dp[i] = 2000000000;
	dp[0] = 0;

	for (int i = 0; i < pow(2, N); i++)
	{
		int x = countBit(i);
		for (int j = 0; j < N; j++)
		{
			if (!(i & (1 << j)))
			{
				dp[i | 1 << j] = min(dp[i | 1 << j], dp[i] + w[x][j]);
			}
		}
	}
	cout << dp[static_cast<int>(pow(2, N)) - 1] << ' ';

}