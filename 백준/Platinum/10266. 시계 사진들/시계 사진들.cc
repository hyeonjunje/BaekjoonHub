#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int origin[720000];
int text[360000];

vector<int> findK()
{
	int m = 360000;

	vector<int> v(m, 0);

	int start = 1, matched = 0;
	while (start + matched < m)
	{
		if (text[start + matched] == text[matched])
		{
			matched++;

			v[start + matched - 1] = matched;
		}
		else
		{
			if (matched == 0) start++;
			else
			{
				start += matched - v[matched - 1];
				matched = v[matched - 1];
			}
		}
	}

	return v;
}

bool kmp()
{
	vector<int> ans;
	int n = 720000, m = 360000;
	vector<int> k = findK();

	int start = 0, matched = 0;

	while (start < n - m)
	{
		if (origin[start + matched] == text[matched])
		{
			matched++;

			if (matched == m)
			{
				return true;
			}
		}
		else
		{
			if (matched == 0) start++;
			else
			{
				start += matched - k[matched - 1];
				matched = k[matched - 1];
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		origin[num] = 1;
		origin[num + 360000] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		text[num] = 1;
	}

	cout << (kmp() ? "possible" : "impossible");
	
}