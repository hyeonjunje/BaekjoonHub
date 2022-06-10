#include<iostream>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

struct Pos
{
	int num;
	double x;
	double y;

	Pos(int num, double x, double y)
		:num(num), x(x), y(y)
	{

	}
};

struct Dist
{
	int from;
	int to;
	double distance;

	Dist(int from, int to, double distance)
		:from(from), to(to), distance(distance)
	{

	}

	bool operator < (const Dist& other) const {
		return distance < other.distance;
	}
};

vector<Dist> tempV;
vector<Pos> v;
set<Dist> s;

int parent[101]{};

int Find(int a)
{
	if (a == parent[a]) return a;
	return parent[a] = Find(parent[a]);
}

bool Union(int a, int b)
{
	a = Find(a), b = Find(b);

	if (a == b) return false;

	parent[b] = a;
	return true;
}

double getDistance(Pos a, Pos b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool comp(Dist a, Dist b)
{
	return a.distance < b.distance;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	double a, b;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back(Pos(i + 1, a, b));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			s.insert(Dist(v[i].num, v[j].num, getDistance(v[i], v[j])));
		}
	}
	for_each(s.begin(), s.end(), [](Dist d) {tempV.push_back(d); });

	double ans = 0;
	
	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 0; i < tempV.size(); i++)
	{
		if (Union(tempV[i].from, tempV[i].to)) ans += tempV[i].distance;
	}

	cout << ans;
}