#include<iostream>
#define MAX 1001

using namespace std;

int dp[MAX];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;

	for (int i = 5; i <= N; i++)
	{
		if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0)
		{
			dp[i] = 1;
		}
		else
		{
			dp[i] = 0;
		}
	}

	cout << (dp[N] == 1 ? "SK" : "CY");
}