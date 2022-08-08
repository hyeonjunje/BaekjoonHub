#include<iostream>
#define MAX 46
using namespace std;

pair<int, int> dp[MAX];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int K;
	cin >> K;

	dp[0] = { 1, 0 };
	for (int i = 1; i <= K; i++)
	{
		dp[i] = { dp[i - 1].second, dp[i - 1].first + dp[i - 1].second };
	}
	cout << dp[K].first << ' ' << dp[K].second;
}