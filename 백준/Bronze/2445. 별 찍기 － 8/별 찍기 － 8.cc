#include<iostream>

using namespace std;

void ans(int N)
{
	int a = 2 * N;
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 1; j <= a; j++)
		{
			if (j <= i) cout << '*';
			else if (a - i < j) cout << '*';
			else cout << ' ';
		}
		cout << '\n';
	}


	for (int i = N + 1; i <= a; i++)
	{
		for (int j = 1; j <= a; j++)
		{
			if (i <= j) cout << '*';
			else if (a + 1 - i >= j) cout << '*';
			else cout << ' ';
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