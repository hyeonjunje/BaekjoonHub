#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int parent[10001]{};

struct Node
{
	int Start;
	int End;
	int distance;

	Node(int Start, int End, int distance)
		:Start(Start), End(End), distance(distance)
	{

	}
};

bool comp(Node a, Node b)
{
	return a.distance < b.distance;
}

vector<Node> v;

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

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int V, E, a, b, c;
	cin >> V >> E;
	for (int i = 1; i <= V; i++) parent[i] = i;

	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;

		v.push_back(Node(a, b, c));
	}
	sort(v.begin(), v.end(), comp);
	
	int ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		Node current = v[i];
		if (Union(current.Start, current.End)) ans += current.distance;
	}
	cout << ans;
}