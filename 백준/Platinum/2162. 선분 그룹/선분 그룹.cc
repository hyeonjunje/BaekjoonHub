#include<iostream>
#include<algorithm>

#define pii pair<int, int>
#define ppii pair<pii, pii>

using namespace std;

int parent[3001];
int b[3001];
ppii lines[3001];

int ccw(pii a, pii b, pii c)
{
	int ans = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);

	if (ans > 0) return 1;
	else if (ans < 0) return -1;
	else return 0;
}

int Find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	a = Find(a), b = Find(b);

	if (a <= b) parent[b] = a;
	else parent[a] = b;
}

bool Check(ppii a, ppii b)
{
	int ab = ccw(b.first, a.first, a.second) * ccw(b.second, a.first, a.second);
	int cd = ccw(a.first, b.first, b.second) * ccw(a.second, b.first, b.second);

	if (ab == 0 && cd == 0)
	{
		if (a.first > a.second) swap(a.first, a.second);
		if (b.first > b.second) swap(b.first, b.second);

		if (a.first <= b.second && a.second >= b.first) return true;
		else return false;
	}
	else if (ab <= 0 && cd <= 0)
	{
		return true;
	}
	return false;

}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, x1, y1, x2, y2;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
		cin >> x1 >> y1 >> x2 >> y2;

		lines[i] = { {x1, y1}, {x2, y2} };
	}

	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (Check(lines[i], lines[j])) Union(i, j);
		}
	}
	int count = 0;
	for (int i = 1; i <= N; i++)
	{
		int f = Find(i);
		if (b[f] == 0) count++;
		b[f]++;
	}
	cout << count << '\n';
	cout << *max_element(b, b + N + 1);
}