#include<iostream>
#include<string>
#define MOD 1000000
#define MAX 5001
using namespace std;

int dp[MAX];
int num[MAX];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;

	int idx = 0;
	if (s[0] == '0')
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (i + 1 < s.size() && (s[i] - '0') * 10 + s[i + 1] - '0' == 10)
		{
			num[idx] = 10;
			idx++;
			i++;
		}
		else if (i + 1 < s.size() && (s[i] - '0') * 10 + s[i + 1] - '0' == 20)
		{
			num[idx] = 20;
			idx++;
			i++;
		}
		else if ((s[i] - '0') == 0)
		{
			cout << 0;
			return 0;
		}
		else if (i + 1 < s.size() && (((s[i] - '0') * 10 + s[i + 1] - '0') % 10 == 0))
		{
			cout << 0;
			return 0;
		}
		else
		{
			num[idx] = s[i] - '0';
			idx++;
		}
	}


	dp[0] = 0;
	dp[1] = 1;

	if (num[1] == 10)
		dp[2] = num[0] * 100 + num[1] <= 26 ? 2 : 1;
	else
		dp[2] = num[0] * 10 + num[1] <= 26 ? 2 : 1;


	for (int i = 3; i <= idx; i++)
	{
		dp[i] = dp[i - 1] % MOD;

		int sumNum;

		if (num[i - 1] == 10)
		{
			sumNum = num[i - 2] * 100 + num[i - 1];
		}
		else
		{
			sumNum = num[i - 2] * 10 + num[i - 1];
		}


		if (sumNum <= 26)
		{
			dp[i] += dp[i - 2] % MOD;
		}
		dp[i] = dp[i] % MOD;
	}


	cout << dp[idx];
}