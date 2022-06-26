#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

vector<string> split(string sentence, char Separator)
{
	vector<string> answer;
	stringstream ss(sentence);
	string tmp;

	while (getline(ss, tmp, Separator))
	{
		answer.push_back(tmp);
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	string s;
	while (N--)
	{
		cin >> s;
		vector<string> v = split(s, ',');
		cout << stoi(v[0]) + stoi(v[1]) << '\n';
	}
}