#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	bool num[20]{};

	int N, n = 1;
	cin >> N;
	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		

		if (s == "add")
		{
			cin >> n;
			num[n - 1] = true;
		}
		else if (s == "remove")
		{
			cin >> n;
			num[n - 1] = false;
		}
		else if (s == "check")
		{
			cin >> n;
			cout << (num[n - 1] ? 1 : 0) << '\n';
		}
		else if (s == "toggle")
		{
			cin >> n;
			if (num[n - 1]) num[n - 1] = false;
			else num[n - 1] = true;
		}
		else if (s == "all")
		{
			for (int j = 0; j < 20; j++)
				num[j] = true;
		}
		else if (s == "empty")
		{
			for (int j = 0; j < 20; j++)
				num[j] = false;
		}
	}
}