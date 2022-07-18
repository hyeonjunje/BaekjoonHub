#include<iostream>
#include<vector>
#include<string.h>
#include<stack>

#define MAX 20020

using namespace std;

vector<int> graph[MAX];

int id, d[MAX], sccNum[MAX];
bool isFinished[MAX];
stack<int> s;
vector<vector<int>> SCC;

int scc(int current)
{
	int parent = d[current] = ++id;
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
			sccNum[t] = SCC.size();
			v.push_back(t);
			isFinished[t] = true;
			if (t == current) break;
		}
		SCC.push_back(v);
	}
	return parent;
}

int neg(int x)
{
	if (x > 10000) return x - 10000;
	else return x + 10000;
}

int main()
{
	int N, M;
	cin >> N >> M;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		//if (a < 0) a = 10000 - a;
		//if (b < 0) b = 10000 - b;

		graph[10000 + -a].push_back(10000 + b);
		graph[10000 + -b].push_back(10000 + a);
	}

	for (int i = 10000 - N; i <= 10000 + N; i++)
	{
		if (d[i] == -1 && i != 10000)
			scc(i);
	}

	for (int i = 1; i <= N; i++)
	{
		//cout << sccNum[10000 + i] << ' ' << sccNum[10000 - i] << '\n';
		if (sccNum[10000 + i] == sccNum[10000 - i])
		{
			cout << 0;
			return 0;
		}
	}

	cout << 1 << '\n';
	for (int i = 1; i <= N; i++)
	{
		cout << (sccNum[10000 + i] < sccNum[10000 - i]) << ' ';
	}
}
