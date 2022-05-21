#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

bool isNumber(const string& str)
{
	for (char const& c : str)
	{
		if (isdigit(c) == 0) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	string name;
	unordered_map<string, int> um1;
	unordered_map<int, string> um2;

	for (int i = 1; i <= N; i++)
	{
		cin >> name;
		um1[name] = i;
		um2[i] = name;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> name;
		if (isNumber(name)) cout << um2[stoi(name)] << '\n';
		else cout << um1[name] << '\n';
	}
}