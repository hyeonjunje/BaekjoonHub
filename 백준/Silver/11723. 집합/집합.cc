#include<iostream>

using namespace std;

int N, BIT, n;
string s;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	while (N--)
	{
		cin >> s;
		if (s == "add")
		{
			cin >> n;
			BIT |= (1 << n);
		}
		else if (s == "remove")
		{
			cin >> n;
			BIT &= ~(1 << n);
		}
		else if (s == "check")
		{
			cin >> n;
			if (BIT & (1 << n)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (s == "toggle")
		{
			cin >> n;
			BIT ^= (1 << n);
		}
		else if (s == "all")
		{
			BIT = (1 << 21) - 1;
		}
		else if (s == "empty")
		{
			BIT = 0;
		}
	}
}