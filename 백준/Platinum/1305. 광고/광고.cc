#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;

vector<int> findK(string s)
{
	int m = s.size();
	vector<int> v(m, 0);
	int start = 1, matched = 0;

	while (start + matched < m)
	{
		if (s[start + matched] == s[matched])
		{
			matched++;

			v[start + matched - 1] = matched;
		}
		else
		{
			if (matched == 0)
			{
				start++;
			}
			else
			{
				start += matched - v[matched - 1];
				matched = v[matched - 1];
			}
		}
	}
	return v;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	string s;

	cin >> N;
	cin >> s;

	vector<int> v = findK(s);

	cout << N - v[N - 1];
}