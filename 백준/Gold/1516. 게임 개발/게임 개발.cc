#include<iostream>
#include<vector>

#define MAX 501
using namespace std;

vector<int> graph[MAX];
int Time[MAX];
int dp[MAX];

int ans(int current)
{
	if (dp[current] != 0) return dp[current];
	dp[current] = Time[current];
	int m = 0;
	for (int i : graph[current])
	{
		m = max(ans(i), m);
	}
	dp[current] += m;
	return dp[current];
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Time[i];

		int flag;
		while (1)
		{
			cin >> flag;
			if (flag == -1) break;

			graph[i].push_back(flag);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		ans(i);
		cout << dp[i] << '\n';
	}
}