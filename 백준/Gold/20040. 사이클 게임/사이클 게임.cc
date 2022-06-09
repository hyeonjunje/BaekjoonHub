#include<iostream>

using namespace std;

int ans = 0;
int root[500001]{};

int Find(int a)
{
	if (a == root[a]) return a;
	return root[a] = Find(root[a]);
}

bool Union(int a, int b)
{
	a = Find(a), b = Find(b);
	ans++;
	// 사이클이 생김
	if (a == b) return true;
	// 작으면 부모
	if (a < b) root[b] = a;
	else root[a] = b;

	return false;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m, a, b;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) root[i] = i;
	
	int answer = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		if (Union(a, b)) { answer = ans;  break; }
	}
	cout << answer;
}