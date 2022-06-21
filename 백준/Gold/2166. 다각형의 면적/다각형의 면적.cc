#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<pair<double, double>> v;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	double x, y;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		v.push_back({ x, y });
	}

	double ans = 0;

	pair<double, double> standard = v[0];

	for (int i = 1; i < v.size() - 1; i++)
	{
		pair<double, double> point1 = v[i];
		pair<double, double> point2 = v[i + 1];

		ans += ((point1.first - standard.first) * (point2.second - standard.second) - (point1.second - standard.second) * (point2.first - standard.first)) / 2.0;
	}
	if (ans < 0) ans *= -1;
	//cout << ans;
	printf("%.1lf", ans);
}
