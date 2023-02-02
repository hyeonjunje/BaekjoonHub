#include<iostream>
#include<cmath>

using namespace std;

double GetDistance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

bool CheckInCircle(double x1, double y1, double x2, double y2, double r)
{
	return r > GetDistance(x1, y1, x2, y2);
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;

	while (T-- != 0)
	{
		double x1, y1, x2, y2, cx, cy, r, n, result = 0;
		cin >> x1 >> y1 >> x2 >> y2;

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> cx >> cy >> r;
			if (CheckInCircle(x1, y1, cx, cy, r) && CheckInCircle(x2, y2, cx, cy, r))
				continue;

			if (CheckInCircle(x1, y1, cx, cy, r) || CheckInCircle(x2, y2, cx, cy, r))
				result++;
		}

		cout << result << endl;
	}
}