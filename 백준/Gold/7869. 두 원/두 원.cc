#include<iostream>
#include<math.h>
#include<algorithm>

# define PI 3.14159265358979323846

using namespace std;

double getDistance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double getSector(double r, double theta)
{
	return pow(r, 2) * PI * (theta / (2 * PI)) - (pow(r, 2) / 2) * sin(theta);
}

double getTheta(double r1, double r2, double d)
{
	return 2 * acos((pow(r1, 2) + pow(d, 2) - pow(r2, 2)) / (2 * r1 * d));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	double distance12 = getDistance(x1, y1, x2, y2);

	cout << fixed;
	cout.precision(3);

	// 떨어져 있을 때
	if (r1 + r2 <= distance12) cout << 0.000;
	// 작은 원이 큰 원 안에 있을 때
	else if (max(r2, r1) >= min(r1, r2) + distance12) cout << PI * pow(min(r1, r2), 2);
	else
	{
		double theta1 = getTheta(r1, r2, distance12);
		double theta2 = getTheta(r2, r1, distance12);
		cout << getSector(r1, theta1) + getSector(r2, theta2);
	}
}