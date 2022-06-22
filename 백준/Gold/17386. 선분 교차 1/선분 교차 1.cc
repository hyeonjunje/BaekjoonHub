#include<iostream>

#define ll long long

using namespace std;

int ccw(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3)
{
	ll op = (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);
	if (op > 0) return 1;
	else return -1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	pair<ll, ll> p1, p2, p3, p4;
	cin >> p1.first >> p1.second;
	cin >> p2.first >> p2.second;
	cin >> p3.first >> p3.second;
	cin >> p4.first >> p4.second;
	
	if (ccw(p3, p1, p2) * ccw(p4, p1, p2) <= 0 && ccw(p1, p3, p4) * ccw(p2, p3, p4) <= 0) cout << 1;
	else cout << 0;
}
