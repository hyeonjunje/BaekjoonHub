#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	double X, Y, D, T;

	cin >> X >> Y >> D >> T;

	double distance = sqrt(X * X + Y * Y);

	double time = 0;

	if (distance < D)
	{
		// 그냥 걷기
		time = distance;

		// 넘고 돌아오기
		time = min(time, T + D - distance);

		// 꺽어서 가기
		time = min(time, 2 * T);
	}
	else
	{
		// 그냥 걷기
		time = distance;

		// 점프로 갔다가 걷기
		
		time = min(time, T * static_cast<int>(distance / D) + distance - D * static_cast<int>(distance / D));

		// 꺽어서 가기
		time = min(time, T * (static_cast<int>(distance / D) + 1));
	}
	cout << fixed;
	cout.precision(9);
	cout << time;
}