#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include <iomanip>

using namespace std;

struct Edge
{
	int from;
	int to;
	double dist;
};

int parent[1001]{};

vector<pair<int, pair<int, int>>> v; // 번호, x좌표, y좌표

int Find(int a)
{
	if (a == parent[a]) return a;
	return parent[a] = Find(parent[a]);
}

bool Union(int a, int b) // 사이클이 있으면 false 없으면 true
{
	a = Find(a), b = Find(b);

	if (a == b) return false;

	// 작은게 부모
	if (a < b) parent[b] = a;
	else parent[a] = b;
	return true;
}

double getDistance(double x1, double x2, double y1, double y2)
{
	//return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	long long dx = x2 - x1;
	long long dy = y2 - y1;
	long long dis = dx * dx + dy * dy;
	return sqrt(dis);
}

bool comp(Edge a, Edge b)
{
	return a.dist < b.dist;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	int a, b;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 1; i <= N; i++)
	{
		cin >> a >> b;
		v.push_back({ i, {a, b} });
	}

	for (int i = 0; i < M; i++)
	{
		int aa, bb;
		cin >> aa >> bb;
		Union(aa, bb);
	}

	vector<Edge> edgeV;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			double dist = getDistance(v[i].second.first, v[j].second.first, v[i].second.second, v[j].second.second);
			edgeV.push_back({ v[i].first, v[j].first, dist });
		}
	}
	sort(edgeV.begin(), edgeV.end(), comp);

	double ans = 0.00;
	for (int i = 0; i < edgeV.size(); i++)
	{
		if (Union(edgeV[i].from, edgeV[i].to)) ans += edgeV[i].dist;
	}
	printf("%.2lf\n", ans);
}