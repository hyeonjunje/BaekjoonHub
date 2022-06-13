#include<iostream>

using namespace std;

int ans[200001][26];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;
	char c;
	int l, r;
	int q;
	cin >> q;

	string alpha = "abcdefghijklmnopqrstuvwxyz";

	for (int a = 0; a < alpha.size(); a++)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (alpha[a] == s[i]) ans[i + 1][a] = ans[i][a] + 1;
			else ans[i + 1][a] = ans[i][a];
		}
	}

	while (q--)
	{
		cin >> c;
		cin >> l >> r;

		cout << ans[r + 1][c - 97] - ans[l][c - 97] << '\n';
	}
}