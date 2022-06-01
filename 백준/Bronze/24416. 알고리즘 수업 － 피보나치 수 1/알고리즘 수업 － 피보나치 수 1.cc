#include<iostream>

using namespace std;

int ans1 = 0;
int ans2 = 0;

int fib(int n)  // 재귀
{
	if (n == 1 || n == 2) {   return 1; }
	else { ans1++; return fib(n - 1) + fib(n - 2); }
}

int fibonacci(int n)  // 동적 프로그래밍
{
	int f[41]{};
	f[1] = 1, f[2] = 1;
	for (int i = 3; i < 41; i++)
	{
		f[i] = f[n - 1] + f[n - 2];
	}
	return n - 2;
}

int main()
{
	int n;

	cin >> n;

	fib(n);
	cout << ans1 + 1 << ' ' << n - 2;
}