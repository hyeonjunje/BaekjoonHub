#include<iostream>

#define ll long long

using namespace std;

void findPoint(pair<ll, ll> A, pair<ll, ll> B, pair<ll, ll> C, pair<ll, ll> D)
{
	double px = (A.first * B.second - A.second * B.first) * (C.first - D.first) - (A.first - B.first) * (C.first * D.second - C.second * D.first);
	double py = (A.first * B.second - A.second * B.first) * (C.second - D.second) - (A.second - B.second) * (C.first * D.second - C.second * D.first);
	double p = (A.first - B.first) * (C.second - D.second) - (A.second - B.second) * (C.first - D.first);

	if (p == 0)
	{
		if (B == C && A <= C) cout << B.first << ' ' << B.second << '\n';
		else if (A == D && C <= A) cout << A.first << ' ' << A.second << '\n';
	}
	else
	{
		double x = px / p;
		double y = py / p;

		cout << fixed;
		cout.precision(9);
		cout << x << ' ' << y;
	}

}

int ccw(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3)
{
	ll ans = (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);

	if (ans > 0) return 1;
	else if (ans < 0) return -1;
	else return 0;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	pair<ll, ll> p1, p2, p3, p4;

	cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second >> p4.first >> p4.second;

	int ab = ccw(p3, p1, p2) * ccw(p4, p1, p2);
	int cd = ccw(p1, p3, p4) * ccw(p2, p3, p4);

	if (ab == 0 && cd == 0)
	{
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);

		if (p1 <= p4 && p2 >= p3)
		{
			cout << 1 << '\n';
			findPoint(p1, p2, p3, p4);
		}
		else cout << 0;
	}
	else if (ab <= 0 && cd <= 0)
	{
		cout << 1 << '\n';
		findPoint(p1, p2, p3, p4);
	}
	else cout << 0;
}