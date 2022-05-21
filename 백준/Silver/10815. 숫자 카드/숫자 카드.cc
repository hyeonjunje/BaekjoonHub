#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	unordered_map<int, bool> um;

	int n, m, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		um[num] = true;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		
		cout << um[num] << ' ';
	}
}