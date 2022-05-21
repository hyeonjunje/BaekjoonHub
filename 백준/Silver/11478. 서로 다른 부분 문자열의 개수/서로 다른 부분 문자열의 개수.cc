#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	unordered_map<string, bool> um;

	string s;
	cin >> s;

	int stringSize = s.length();

	for (int i = 1; i <= s.length(); i++)
		for (int j = 0; j < s.length(); j++)
			um[s.substr(j, i)] = true;

	cout << um.size();
}