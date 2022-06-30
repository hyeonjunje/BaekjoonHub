#include<iostream>

using namespace std;

string dp[1001]{};

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	dp[1] = "SK";

	for (int i = 2; i <= N; i++)
	{
		if (dp[i - 1] == "CY" || (i >= 4 && dp[i - 3] == "CY"))
			dp[i] = "SK";
		else
			dp[i] = "CY";
	}

	cout << dp[N];
}