#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

#define MAX 10001

using namespace std;

int V, E, A, B;

int id, d[MAX];
vector<int> graph[MAX];
stack<int> s;
bool finished[MAX];
vector<vector<int>> SCC;

int dfs(int current)
{
	d[current] = ++id;

	s.push(current);
	int parent = d[current];

	for (int i = 0; i < graph[current].size(); i++)
	{
		int next = graph[current][i];

		if (d[next] == 0)
		{
			parent = min(parent, dfs(next));
		}
		else if (!finished[next])
		{
			parent = min(parent, d[next]);
		}
	}
	if (parent == d[current])
	{
		vector<int> v;
		while (1)
		{
			int t = s.top();
			s.pop();
			v.push_back(t);
			finished[t] = true;
			if (t == current) break;
		}
		sort(v.begin(), v.end());
		SCC.push_back(v);
	}
	return parent;
}

bool temp(vector<int> a, vector<int> b)
{
	return a[0] < b[0];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		cin >> A >> B;
		graph[A].push_back(B);
	}

	for (int i = 1; i <= V; i++)
	{
		if (d[i] == 0) dfs(i);
	}

	sort(SCC.begin(), SCC.end(), temp);

	cout << SCC.size() << '\n';

	for (vector<int> v : SCC)
	{
		for (int i : v)
		{
			cout << i << ' ';
		}
		cout << -1 << '\n';
	}
}