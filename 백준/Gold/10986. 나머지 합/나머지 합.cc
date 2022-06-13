#include<iostream>

using namespace std;

long long num[1001]{};


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, a;
	cin >> N >> M;
	long long sum = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> a;
		sum += a;
		num[sum % M]++;
	}
	long long ans = 0;
	for (int i = 0; i < M; i++)
	{
		ans += num[i] * (num[i] - 1) / 2;
	}

	cout << ans + num[0];
}