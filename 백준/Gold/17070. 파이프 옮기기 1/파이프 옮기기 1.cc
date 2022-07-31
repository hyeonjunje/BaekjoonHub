#include<iostream>
#include<utility>
#define MAX 17
using namespace std;


int dp[MAX][MAX];
int house[MAX][MAX];
int N;
int answer = 0;
int dr[3] = { 0, 1, 1 };
int dc[3] = { 1, 0, 1 };

bool chk(int r, int c)
{
	if (r > N || c > N || house[r][c] == 1) return false;
	return true;
}

void dfs(int r, int c, int dir)
{
	if (r == N && c == N)
	{
		answer++;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if ((dir == 0 && i == 1) || (dir == 1 && i == 0)) continue;

		int nr = r + dr[i];
		int nc = c + dc[i];
		if (chk(nr, nc) == false) continue;
		if (i == 2 && (house[r + 1][c] == 1 || house[r][c + 1] == 1)) continue;
		dfs(nr, nc, i);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> house[i][j];

	dfs(1, 2, 0);
	cout << answer;
}