#include<iostream>

using namespace std;


#define MAX 100001

int inOrder[MAX], postOrder[MAX], idx[MAX];

void dfs(int s1, int e1, int s2, int e2)
{
	if (s1 > e1 || s2 > e2) return;

	int root = postOrder[e2];
	cout << root << ' ';

	// left
	dfs(s1, idx[root] - 1, s2, s2 + idx[root] - s1 - 1);

	// right
	dfs(idx[root] + 1, e1, s2 + idx[root] - s1, e2 - 1);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> inOrder[i];
	for (int i = 0; i < n; i++) cin >> postOrder[i];
	for (int i = 0; i < n; i++)
	{
		idx[inOrder[i]] = i;
	}

	dfs(0, n - 1, 0, n - 1);
}