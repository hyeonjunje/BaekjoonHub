#include<iostream>
#include<vector>
#define MOD 1000000007
using namespace std;

typedef vector<vector<long long>> matrix;

matrix operator * (const matrix& a, const matrix& b)
{
	int n = a.size();

	matrix c(n, vector<long long>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= MOD;
		}

	}
	return c;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	matrix ans = { {1, 0}, {0, 1} };
	matrix a = { {1, 1}, {1, 0} };

	long long N;
	cin >> N;
	while (N > 0)
	{
		if (N % 2 == 1)
			ans = ans * a;
		a = a * a;
		N /= 2;
	}

	cout << ans[0][1];
}