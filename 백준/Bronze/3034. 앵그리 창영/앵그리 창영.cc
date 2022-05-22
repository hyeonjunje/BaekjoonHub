#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int num, N, W, H;
	cin >> N >> W >> H;
	for (int i = 0; i < N; i++)
	{
		cin >> num;

		cout << (num <= sqrt((pow(W, 2) + pow(H, 2))) ? "DA" : "NE") << '\n';
	}
}