#include<iostream>
#include<stack>
#include<vector>
#include<string.h>

#define MAX 10001

using namespace std;

vector<int> graph[MAX];
vector<vector<int>> SCC;
stack<int> s;
int k, n, id, d[MAX], sccGroup[MAX];
bool isFinished[MAX];

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
			v.push_back(t);
			isFinished[t] = true;
			sccGroup[t] = SCC.size();
			if (t == current) break;
		}
		SCC.push_back(v);
	}
	return parent;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	cin >> k >> n;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; i++)
	{
		/// R은 true, B는 false로 봄
		int a, b, c;
		char c1, c2, c3;
		cin >> a >> c1 >> b >> c2 >> c >> c3;
		if (c1 == 'B') a = -a;
		if (c2 == 'B') b = -b;
		if (c3 == 'B') c = -c;

		graph[5000 - a].push_back(5000 + b);
		graph[5000 - b].push_back(5000 + a);
		graph[5000 - a].push_back(5000 + c);
		graph[5000 - c].push_back(5000 + a);
		graph[5000 - b].push_back(5000 + c);
		graph[5000 - c].push_back(5000 + b);
	}

	for (int i = 5000 - k; i <= 5000 + k; i++)
	{
		if (i != 5000 && isFinished[i] == false)
		{
			scc(i);
		}
	}

	for (int i = 1; i <= k; i++)
	{
		if (sccGroup[5000 + i] == sccGroup[5000 - i])
		{
			cout << -1;
			return 0;
		}
	}

	for (int i = 1; i <= k; i++)
	{
		cout << (sccGroup[5000 + i] < sccGroup[5000 - i] ? 'R' : 'B');
	}
}