#include<iostream>
#include<math.h>
#define MAX 50001
using namespace std;

int dp[MAX];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		if (i * i >= MAX) break;
		dp[i * i] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		if (dp[i] == 1) continue;
		dp[i] = MAX;
		for (int j = (int)sqrt(i); j >= 1; j--)
		{
			dp[i] = min(dp[i], dp[j * j] + dp[i - (j * j)]);
		}

		//dp[i] = dp[(int)sqrt(i) * (int)sqrt(i)] + dp[i - ((int)sqrt(i) * (int)sqrt(i))];
	}

	cout << dp[N];
}