#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

#define MAX 1000001

int parent[MAX]{};

int myFind(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = myFind(parent[x]);
}

void myUnion(int a, int b)
{
	a = myFind(a);
	b = myFind(b);

	parent[b] = a;
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m, a, b, flag;
	cin >> n >> m;

	// 처음에는 자기자신이 부모
	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++)
	{
		cin >> flag >> a >> b;

		if (flag == 1) cout << (myFind(a) == myFind(b) ? "YES" : "NO") << '\n';
		else myUnion(a, b);
	}

	
}