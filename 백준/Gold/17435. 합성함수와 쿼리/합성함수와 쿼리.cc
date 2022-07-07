//효율적인 LCA 구현을 위해 필요한 sparse table 자료구조를 배워 봅시다.
#include<iostream>
#include<math.h>

using namespace std;

#define MAXLOG 19
#define MAX 200001

int y[MAX][MAXLOG];  // x를 2^(i)번 f한 결과

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int m, Q, n, x;
	cin >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> y[i][0];
	}

	for (int j = 1; j < MAXLOG; j++)
	{
		for (int i = 1; i <= m; i++)
		{
			y[i][j] = y[y[i][j - 1]][j - 1];
		}
	}

	cin >> Q;
	while (Q--)
	{
		cin >> n >> x;

		for (int i = 0; n; i++)
		{
			if (n % 2) x = y[x][i];
			n >>= 1;
		}

		cout << x << '\n';
	}
}