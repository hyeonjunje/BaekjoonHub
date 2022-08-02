#include<iostream>

#define MAX 1000001
#define MOD 1000000009

using namespace std;
long long dp[MAX] = {0, 1, 2, 4};
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, a;
	cin >> N;


	for (int i = 4; i < MAX; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	}
	
	while (N--)
	{
		cin >> a;
		cout << dp[a] << '\n';
	}
}