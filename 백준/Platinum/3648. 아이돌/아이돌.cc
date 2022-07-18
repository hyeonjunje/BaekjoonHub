#include<iostream>
#include<vector>
#include<stack>
#include<string.h>

#define MAX 2002

using namespace std;

int n, m, id, d[MAX], sccGroup[MAX];
vector<int> graph[MAX];
bool isFinished[MAX];
stack<int> s;
vector<vector<int>> SCC;

int scc(int current)
{
	int parent = d[current] = id++;
	s.push(current);

	for (int next : graph[current])
	{
		if (d[next] == -1) parent = min(parent, scc(next));
		else if (isFinished[next] == false) parent = min(parent, d[next]);
	}

	if (parent == d[current])
	{
		vector<int> v;
		while (1)
		{
			int t = s.top();
			s.pop();
			sccGroup[t] = SCC.size();
			v.push_back(t);
			isFinished[t] = true;
			if (current == t) break;
		}
		SCC.push_back(v);
	}
	return parent;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	while (cin >> n)
	{
		cin >> m;

		bool flag = true;
		memset(d, -1, sizeof(d));
		memset(sccGroup, 0, sizeof(sccGroup));
		memset(isFinished, false, sizeof(isFinished));
		SCC.clear();
		for (int i = 1; i <= n; i++)
		{
			graph[1000 - i].clear();
			graph[1000 + i].clear();
		}

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[1000 - a].push_back(1000 + b);
			graph[1000 - b].push_back(1000 + a);
		}
		graph[999].push_back(1001);

		for (int i = 1000 - n; i <= 1000 + n; i++)
		{
			if (i != 1000 && isFinished[i] == false)
				scc(i);
		}

		for (int i = 1; i <= n; i++)
		{
			if (sccGroup[1000 + i] == sccGroup[1000 - i])
			{
				flag = false;
				cout << "no" << '\n';
				break;
			}
		}
		if(flag)
			cout << "yes" << '\n';
		//if (d[1001] > d[999])
		//{
		//	flag = false;
		//	cout << "no" << '\n';
		//}
		//else if (flag)
		//	cout << "yes" << '\n';
	}
}