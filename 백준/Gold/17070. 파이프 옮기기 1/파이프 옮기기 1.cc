#include<iostream>
#include<utility>
#define MAX 33
using namespace std;


long long dp[MAX][MAX][3];
int house[MAX][MAX];
int N;

enum class Dir {
	Horizontal,
	Vertical,
	Diagonal
};

void solve()
{
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			// 가로
			if (r <= N && c + 1 <= N && house[r][c + 1] == 0)
			{
				dp[r][c + 1][(int)Dir::Horizontal] += dp[r][c][(int)Dir::Horizontal];
				dp[r][c + 1][(int)Dir::Horizontal] += dp[r][c][(int)Dir::Diagonal];
			}
			// 세로
			if (r + 1 <= N && c <= N && house[r + 1][c] == 0)
			{
				dp[r + 1][c][(int)Dir::Vertical] += dp[r][c][(int)Dir::Vertical];
				dp[r + 1][c][(int)Dir::Vertical] += dp[r][c][(int)Dir::Diagonal];
			}
			// 대각선
			if (r + 1 <= N && c + 1 <= N && house[r + 1][c] == 0 && house[r][c + 1] == 0 && house[r + 1][c + 1] == 0)
			{
				dp[r + 1][c + 1][(int)Dir::Diagonal] += dp[r][c][(int)Dir::Horizontal];
				dp[r + 1][c + 1][(int)Dir::Diagonal] += dp[r][c][(int)Dir::Vertical];
				dp[r + 1][c + 1][(int)Dir::Diagonal] += dp[r][c][(int)Dir::Diagonal];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> house[i][j];


	dp[1][2][(int)Dir::Horizontal] = 1;
	solve();
	

	cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2] << '\n';
}