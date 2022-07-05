#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;

int adj[501][501]{};
int inDegree[501]{};
int result[501]{};
int n;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int c = 0;
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		vector<int> tmp(n);

		for (int i = 0; i < n; i++)
		{
			cin >> tmp[i];
			inDegree[i] = 0;
			for (int j = 0; j < n; j++)
			{
				adj[i + 1][j + 1] = false;
			}
		}
		inDegree[n] = 0;

		for (int i = 0; i < n; i++)
		{
			int a = tmp[i];
			for (int j = i + 1; j < n; j++)
			{
				int b = tmp[j];
				adj[a][b] = true;
				inDegree[b]++;
			}
		}	

		int m; cin >> m;

		for (int i = 0; i < m; i++)
		{
			int from, to;
			cin >> from >> to;
			if (adj[from][to])
			{
				adj[from][to] = false;
				adj[to][from] = true;
				inDegree[to]--;
				inDegree[from]++;
			}
			else
			{
				adj[to][from] = false;
				adj[from][to] = true;
				inDegree[from]--;
				inDegree[to]++;
			}
		}

		queue<int> q;
		for (int i = 1; i <= n; i++)
			if (inDegree[i] == 0) q.push(i);

		for (int i = 1; i <= n; i++)
		{
			if (q.empty())
			{
				cout << "IMPOSSIBLE" << '\n';
				goto ENDLOOP;
			}
			if (q.size() > 1)
			{
				cout << "?" << '\n';
				goto ENDLOOP;
			}

			int now = q.front();
			result[i] = now;
			q.pop();
			inDegree[now]--;
			for (int i = 1; i <= n; i++)
			{
				if (adj[now][i]) inDegree[i]--;
				if (inDegree[i] == 0) q.push(i);
			}
		}

		for (int i = 1; i <= n; i++)
		{
			cout << result[i] << ' ';
		}
		cout << '\n';


		ENDLOOP:;
	}


}