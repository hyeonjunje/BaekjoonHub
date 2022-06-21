#include<iostream>

using namespace std;

void ans(int N)
{
	int a = 2 * N;
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 1; j < a; j++)
		{
			if (N - i + 1 > j) cout << ' ';
			else if (N - i + 1 <= j && j <= N + i - 1) cout << '*';
		}
		cout << '\n';
	}

	for (int j = 1; j < a; j++) cout << '*';
	cout << '\n';

	for (int i = N - 1; i >= 1; i--)
	{
		for (int j = 1; j < a; j++)
		{
			if(N - i + 1 > j) cout << ' ';
			else if (N - i + 1 <= j && j <= N + i - 1) cout << '*';
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	
	ans(N);
}