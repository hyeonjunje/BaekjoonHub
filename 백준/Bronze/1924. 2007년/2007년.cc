#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	int Date[13]{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string day[7]{ "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	int m, d;
	cin >> m >> d;

	int dateDiff = 0;

	for (int i = 1; i < m; i++)
		dateDiff += Date[i];

	dateDiff += d - 1;

	cout << day[dateDiff % 7];
}