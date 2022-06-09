#include<iostream>

using namespace std;

int n[100001]{};

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, num, s, e;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		n[i] = n[i - 1] + num;
	}
	for (int i = 0; i < M; i++)
	{
		int ans = 0;
		cin >> s >> e;

		cout << n[e] - n[s - 1] << '\n';
	}
}