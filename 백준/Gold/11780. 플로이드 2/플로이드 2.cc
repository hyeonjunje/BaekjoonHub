#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

int INF = 200000000;

int n, m;
int dp[101][101]{};

vector<int> dpV[101][101]{};

void floydWarshall()
{
	for (int i = 1; i <= n; i++)
	{
		for (int row = 1; row <= n; row++)
		{
			for (int col = 1; col <= n; col++)
			{
				if (dp[row][col] > dp[row][i] + dp[i][col])
				{
					dp[row][col] = dp[row][i] + dp[i][col];
					dpV[row][col] = {};
					for (int j = 0; j < dpV[row][i].size(); j++)
					{
						dpV[row][col].push_back(dpV[row][i][j]);
					}

					for (int j = 0; j < dpV[i][col].size(); j++)
					{
						dpV[row][col].push_back(dpV[i][col][j]);
					}
				}
			}
		}
	}
	for (int row = 1; row <= n; row++)
	{
		for (int col = 1; col <= n; col++)
		{
			dpV[row][col].push_back(col);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b, c;

	fill(dp[0], dp[0] + sizeof(dp) / 4, INF);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		dp[a][b] = min(dp[a][b], c);
		dpV[a][b] = { a };
	}

	for (int i = 0; i <= n; i++) dp[i][i] = 0;

	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dpV[i][j] = { i };
		}
	}*/

	floydWarshall();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << (dp[i][j] == INF ? 0 : dp[i][j]) << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dpV[i][j].size() == 1 || dp[i][j] == INF) cout << 0 << '\n';
			else {
				cout << dpV[i][j].size() << ' ';
				for (int k = 0; k < dpV[i][j].size(); k++)
				{
					cout << dpV[i][j][k] << ' ';
				}
				cout << '\n';
			}
		}
	}
}