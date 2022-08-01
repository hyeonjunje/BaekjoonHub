#include<iostream>

#define MAX 1001
using namespace std;

int map[MAX][MAX];
int dp[MAX][MAX];


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j + 1] = s[j] - 48;
		}
	}
	int ans = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] != 0)
			{
				map[i][j] = min(min(map[i - 1][j], map[i][j - 1]), map[i - 1][j - 1]) + 1;
				ans = max(ans, map[i][j]);
			}
		}
	}
	cout << ans * ans;

}