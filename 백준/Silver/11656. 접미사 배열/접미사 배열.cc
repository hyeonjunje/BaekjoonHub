#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;
	vector<string> v;
	
	for (int i = 0; i < s.size(); i++)
	{
		string ss = "";
		for (int j = i; j < s.size(); j++)
		{
			ss += s[j];
		}
		v.push_back(ss);
	}

	sort(v.begin(), v.end());

	for (string s : v)
	{
		cout << s << '\n';
	}
}