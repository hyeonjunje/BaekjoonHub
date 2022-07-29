#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool tmp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.first < p2.first;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, a, b;
	cin >> N;
	vector<pair<int, int>> v;
	while (N--)
	{
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end(), tmp);

	int start = v[0].first, end = v[0].second, len = 0;
	bool flag = true;

	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].first <= end && v[i].second >= end)
		{
			end = v[i].second;
		}
		else if (v[i].first > end)
		{
			len += end - start;
			start = v[i].first;
			end = v[i].second;
		}
	}
	len += end - start;

	cout << len;
}
