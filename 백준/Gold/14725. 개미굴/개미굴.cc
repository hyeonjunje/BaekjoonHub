#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct Trie
{
	Trie() {

	}

	map<string, Trie*> m;

	void Insert(vector<string> s, int idx)
	{
		if (idx == s.size()) return;

		// 없으면 새로 만든다.
		if (m.find(s[idx]) == m.end())
		{
			m.insert({ s[idx], new Trie() });
		}
		m[s[idx]]->Insert(s, idx + 1);
	}

	void Print(int idx)
	{
		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			for (int i = 0; i < idx; i++)
			{
				cout << "--";
			}
			cout << (*iter).first << '\n';

			(*iter).second->Print(idx + 1);
		}
	}
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	Trie* root = new Trie();

	while (N--)
	{
		int num;
		cin >> num;

		vector<string> s(num);

		for (int i = 0; i < num; i++)
		{
			cin >> s[i];
		}

		root->Insert(s, 0);
	}

	root->Print(0);
}