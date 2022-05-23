#include<iostream>
#include<utility>
#include<cmath>

using namespace std;

double getDistance(int x1, int y1, int x2, int y2)
{
	return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}



int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int W, H, X, Y, P;
	cin >> W >> H >> X >> Y >> P;

	double distance = H / 2;
	
	pair<int, int> center1 = { X, Y + distance };
	pair<int, int> center2 = { X + W, Y + distance };

	int x, y, num = 0;
	for (int i = 0; i < P; i++)
	{
		cin >> x >> y;

		if (getDistance(x, y, center1.first, center1.second) <= distance ||
			getDistance(x, y, center2.first, center2.second) <= distance ||
			X <= x && x <= X + W && Y <= y && y <= Y + H)
			num++;
	}
	cout << num;
}