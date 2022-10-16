#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

long long dp[10];

void digitNumberAdd(long long n, int idx)
{
	while (n > 0)
	{
		dp[n % 10] += pow(10, idx);
		n /= 10;
	}
}



// 같은 자릿수의 숫자를 입력하면 그 사이에 있는 숫자를 count한다.
void digitCount(long long a, long long b, int idx)
{
	while (a % 10 != 0 && a <= b)
	{
		digitNumberAdd(a, idx);
		a++;
	}

	if (a > b) return;

	while (b % 10 != 9 && a <= b)
	{
		digitNumberAdd(b, idx);
		b--;
	}


	for (int i = 0; i <= 9; i++)
	{
		dp[i] += (b / 10 - a / 10 + 1) * pow(10, idx);
	}
	digitCount(a / 10, b / 10, idx + 1);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long N;
	cin >> N;

	digitCount(1, N, 0);

	for (int i = 0; i < 10; i++)
	{
		cout << dp[i] << " ";
	}
}