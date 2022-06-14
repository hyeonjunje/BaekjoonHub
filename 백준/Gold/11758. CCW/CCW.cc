#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	int temp = (x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x2 * y1 + x3 * y2);

	if (temp > 0) cout << 1;
	else if (temp < 0) cout << -1;
	else cout << 0;
}