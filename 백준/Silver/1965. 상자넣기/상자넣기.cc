#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<int> v;
	v.push_back(0);
	int n, a;
	cin >> n;
	while (n--)
	{
		cin >> a;
		if (a > v[v.size() - 1])
		{
			v.push_back(a);
		}
		else
		{
			int idx = lower_bound(v.begin(), v.end(), a) - v.begin();
			v[idx] = a;
		}
	}
	cout << v.size() - 1;
}