#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, ans = 0;
	string s;
	cin >> N >> M;
	unordered_map<string, bool> um;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		um[s] = true;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> s;
		if (um[s]) ans++;
	}
	cout << ans;
}