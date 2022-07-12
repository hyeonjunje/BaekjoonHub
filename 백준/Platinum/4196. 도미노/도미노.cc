#include<iostream>
#include<vector>
#include<string.h>
#include<stack>

#define MAX 100001
using namespace std;

vector<int> graph[MAX];

int N, M;
bool visited[MAX];

stack<int> s;

void dfs(int current)
{
	visited[current] = true;

	for (int i = 0; i < graph[current].size(); i++)
	{
		int next = graph[current][i];
		if (visited[next] == false)
		{
			dfs(next);
		}
	}
	s.push(current);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T, x, y;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		int ans = 0;
		memset(visited, false, sizeof(visited));
		while (!s.empty())
		{
			s.pop();
		}
		for (int i = 0; i <= N; i++)
		{
			graph[i].clear();
		}

		for (int i = 0; i < M; i++)
		{
			cin >> x >> y;
			graph[x].push_back(y);
		}

		for (int i = 1; i <= N; i++)
		{
			if(!visited[i])
				dfs(i);
		}
		vector<int> v;

		while (!s.empty())
		{
			int t = s.top();
			s.pop();
			v.push_back(t);
		}

		memset(visited, false, sizeof(visited));

		for (int i : v)
		{
			if (visited[i] == false)
			{
				ans++;
				dfs(i);
			}
		}
		cout << ans << '\n';
	}
}