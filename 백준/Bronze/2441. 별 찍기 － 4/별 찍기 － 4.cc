#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = N; i >= 1; i--)
	{
		for (int j = N; j > 0; j--)
		{
			if (i < j) cout << ' ';
			else cout << '*';
		}
		cout << '\n';
	}
}