#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, num;

	cin >> N;
	vector<int> v;
	stack<pair<int, int>> s;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	long long result = 0;

	for (int i = 0; i < N; i++)
	{
		int sameCount = 1;
		while (!s.empty() && s.top().first <= v[i])
		{
			if (s.top().first == v[i])
				sameCount = s.top().second + 1;
			result += s.top().second;
			s.pop();
		}

		if (!s.empty()) result++;

		s.push({v[i], sameCount});
	}

	cout << result;
}