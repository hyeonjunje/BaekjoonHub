#include<iostream>
#include<stack>
#include<vector>
#include<string.h>
#include<algorithm>

#define MAX 500001

using namespace std;

vector<int> graph[MAX];
vector<int> sccGraph[MAX];
vector<int> invSccGraph[MAX];
int cost[MAX];
int sccCost[MAX];

bool restaurant[MAX];
vector<vector<int>>SCC;
bool isFinished[MAX];
int N, M, S, P, id, d[MAX], sccGroup[MAX];
stack<int> s;

bool isVisited[MAX];
stack<int> ss;

int dp[MAX];

void dfs(int current)
{
	isVisited[current] = true;
	for(int i : sccGraph[current])
	{
		if (isVisited[i] == false)
		{
			dfs(i);
		}
	}
	ss.push(current);
}

//int prevCost = 0;
//int dp[MAX];
//
//void dfs1(int current)
//{
//	dp[current] = max(dp[current], prevCost + sccCost[current]);
//	for (int i : sccGraph[current])
//	{
//		prevCost = dp[current];
//		dfs1(i);
//	}
//}


int scc(int current)
{
	d[current] = ++id;
	int parent = d[current];
	s.push(current);

	for (int next : graph[current])
	{
		if (d[next] == -1)
			parent = min(parent, scc(next));
		else if (isFinished[next] == false)
			parent = min(parent, d[next]);
	}
	if (parent == d[current])
	{
		vector<int> v;
		while (true)
		{
			int t = s.top();
			s.pop();
			sccGroup[t] = SCC.size();
			isFinished[t] = true;
			v.push_back(t);

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
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	for (int i = 1; i <= N; i++)
	{
		if (!isFinished[i])
			scc(i);
	}

	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i];
	}

	for (int i = 1; i <= N; i++)
	{
		sccCost[sccGroup[i]] += cost[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j : graph[i])
		{
			if (sccGroup[i] == sccGroup[j]) continue;
			sccGraph[sccGroup[i]].push_back(sccGroup[j]);
		}
	}

	cin >> S >> P;
	for (int i = 0; i < P; i++)
	{
		int a;
		cin >> a;
		restaurant[sccGroup[a]] = true;
	}

	dfs(sccGroup[S]);
	 vector<int> v;
	while (!ss.empty())
	{
		v.push_back(ss.top());
		ss.pop();
	}

	for (int i = 0; i < SCC.size(); i++)
	{
		for (int j : sccGraph[i])
		{
			invSccGraph[j].push_back(i);
		}
	}

	for (int i : v)
	{
		int maxV = 0;
		dp[i] = sccCost[i];
		for (int j : invSccGraph[i])
		{
			maxV = max(maxV, dp[j]);
		}
		dp[i] += maxV;
	}

	int ans = 0;
	for (int i = 0; i < SCC.size(); i++)
	{
		if (restaurant[i])
		{
			ans = max(ans, dp[i]);
		}
	}
	cout << ans;

	//dfs1(sccGroup[S]);
	//vector<int> v;
	//for (int i = 0; i < SCC.size(); i++)
	//{
	//	if (restaurant[i]) v.push_back(dp[i]);
	//}
	//cout << *max_element(v.begin(), v.end());




	//cout << *max_element(dp[1], dp[1] + SCC.size());

	/*for (int i = 0; i < SCC.size(); i++)
	{
		if (isVisited[i] == false)
			dfs(i);
	}*/
}