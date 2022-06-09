#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;


unordered_map<string, string> um;
unordered_map<string, int> Size;

string Find(string a)
{
	if (a == um[a]) return a;
	return um[a] = Find(um[a]);
}

void Union(string a, string b)
{
	a = Find(a), b = Find(b);

	if (a == b) return;

	if (a > b) { um[a] = b; Size[b] += Size[a];}
	else { um[b] = a; Size[a] += Size[b];}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T, N;
	cin >> T;
	while (T--)
	{
		um.clear();
		Size.clear();
		string a, b;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> a >> b;

			if (um.find(a) == um.end()) um[a] = a;
			if (um.find(b) == um.end()) um[b] = b;
			if (Size.find(a) == Size.end()) Size[a] = 1;
			if (Size.find(b) == Size.end()) Size[b] = 1;

			Union(a, b);

			//cout << "이름은 : " + name << " 루트는 :  " << um[name] <<  " 랭크는 :  "  << Rank[name] << '\n';

			cout << Size[Find(a)] << '\n';
		}
	}
}