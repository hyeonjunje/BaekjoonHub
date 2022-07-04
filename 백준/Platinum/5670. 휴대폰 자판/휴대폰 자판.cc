#include <iomanip>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int ans = 0;
bool fir = false;

struct Trie
{
	Trie() {};
	~Trie() {
		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			delete (*iter).second;
		}
	}
	map<char, Trie*> m;

	void Insert(string word, int idx = 0)
	{
		if (word.size() == idx) { 
			m.insert({ ' ', new Trie()});
			return; 
		}

		// 없으면 새로 만들어줘서 넣어버림
		if (m.find(word[idx]) == m.end())
		{
			m.insert({ word[idx], new Trie() });
		}
		m[word[idx]]->Insert(word, idx + 1);
	}

	void Input(string word, int idx = 0)
	{
		if (idx >= word.size()) return;

		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			if ((*iter).first == word[idx])
			{
				//cout << (*iter).first << ' ' << word[idx] << ' ' << m.size() << '\n';
				if (fir || m.size() != 1)
				{
					fir = false;
					ans++;
				}
				
				(*iter).second->Input(word, idx + 1);
			}
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	while (cin >> N) {

		// 초기화
		Trie* root = new Trie();
		vector<string> words(N);
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			string s;
			cin >> s;
			root->Insert(s);
			words[i] = s;
		}


		for (int i = 0; i < N; i++)
		{
			fir = true;
			//ans = (root->m.size() != 1 ? 0 : 1);
			ans = 0;
			root->Input(words[i]);
			sum += ans;
		}
		cout << fixed << setprecision(2) << double(sum) / double(N) << '\n';
	}
}