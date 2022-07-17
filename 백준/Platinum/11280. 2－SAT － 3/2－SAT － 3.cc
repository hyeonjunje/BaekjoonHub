#include<iostream>
#include<vector>
#include<stack>
#include<string.h>
#define MAX 20002
using namespace std;
vector<int> graph[MAX];

int id, d[MAX];
bool isFinished[MAX];
vector<vector<int>> SCC;
stack<int> s;

int scc(int current)
{
	int parent = d[current] = id++;
	s.push(current);
	for (int next : graph[current])
	{
		if (d[next] == -1)
		{
			parent = min(parent, scc(next));
		}
		else if (isFinished[next] == false)
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
			d[t] = SCC.size();
			v.push_back(t);
			isFinished[t] = true;
			if (t == current) break;
		}
		SCC.push_back(v);
	}
	return parent;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(d, -1, sizeof(d));
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[10000 + -a].push_back(10000 + b);
		graph[10000 + -b].push_back(10000 + a);
	}

	for (int i = 10000 - N; i <= 10000 + N; i++)
	{
		if (i != 10000 && isFinished[i] == false)
			scc(i);
	}

	for (int i = 1; i <= N; i++)
	{
		if (d[10000 + i] == d[10000 - i])
		{
			cout << 0 << '\n';
			return 0;
		}
	}
	cout << 1 << '\n';
}