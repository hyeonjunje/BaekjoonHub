#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1000000001
using namespace std;

bool Descending(pair<long long, long long> p1, pair<int, int> p2)
{
	return p1.first > p2.first;
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long N, M, a, b;
	cin >> N >> M;

	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;

		if(a > b)
			v.push_back({ a, b });
	}

	long long len = M;

	sort(v.begin(), v.end(), Descending);

	if (v.size() != 0)
	{
		long long start = v[0].first, end = v[0].second;
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i].first < end)
			{
				len += 2 * (start - end);

				start = v[i].first, end = v[i].second;
			}
			else if (v[i].second < end)
			{
				end = v[i].second;
			}
		}
		len += 2 * (start - end);
	}
	cout << len;
	
}