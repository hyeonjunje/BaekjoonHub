#include<iostream>
#include<string>
#include<vector>


using namespace std;


vector<int> getPi(string p)
{
	int m = (int)p.size();
	vector<int> pi(m, 0);
	
	int begin = 1, matched = 0;

	while (begin + matched < m)
	{
		if (p[begin + matched] == p[matched])
		{
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else
		{
			if (matched == 0) begin++;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string T, P;
	getline(cin, T);
	getline(cin, P);

	vector<int> t = getPi(P);

	vector<int> ans;

	int begin = 0, matched = 0;
	int n = T.size(), m = P.size();
	while (begin <= n - m)
	{
		if (matched < m && T[begin + matched] == P[matched])
		{
			matched++;

			if (matched == m)
			{
				ans.push_back(begin);
			}
		}
		else
		{
			if (matched == 0)
			{
				begin++;
			}
			else
			{
				begin += matched - t[matched - 1];
				matched = t[matched - 1];
			}
		}
	}
	cout << ans.size() << '\n';
	for (int i : ans) cout << i + 1 << ' ';
	
}