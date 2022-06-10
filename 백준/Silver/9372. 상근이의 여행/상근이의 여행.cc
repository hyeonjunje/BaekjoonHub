#include<iostream>
#include<vector>
#include<string.h>

using namespace std;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T, N, M, a, b;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
		}
		cout << N - 1 << '\n';
	}
}