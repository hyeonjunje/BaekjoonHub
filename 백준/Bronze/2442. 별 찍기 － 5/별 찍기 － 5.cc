#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = N; i >= 1; i--)
	{
		for (int h = 0; h < i - 1; h++) cout << ' ';
		for (int h = 0; h < N - i + N - i + 1; h++) cout << '*';

		cout << '\n';
	}
}