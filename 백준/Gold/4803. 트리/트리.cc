#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

vector<int> graph[501]{};

int treeCount;
int n, m, a, b;

bool visited[501]{};

void checkTree(int caseNumber)
{
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++)
	{
		bool isCycle = false;

		if (visited[i] == false)
		{
			treeCount++;
			q.push({i, 0});
			visited[i] = true;

			while (!q.empty())
			{
				int current = q.front().first;
				int from = q.front().second;

				q.pop();

				for (int i = 0; i < graph[current].size(); i++)
				{
					// 연결되어 있다는 거임
					if (graph[current][i] != from && visited[graph[current][i]])
					{
						isCycle = true;
					}

					else if (visited[graph[current][i]] == false)
					{
						visited[graph[current][i]] = true;
						q.push({ graph[current][i], current });
					}
				}
			}
			if (isCycle) treeCount--;
		}
	}

	if (treeCount > 1) cout << "Case " << caseNumber << ": A forest of " << treeCount << " trees." << '\n';
	else if (treeCount == 1) cout << "Case " << caseNumber << ": There is one tree." << '\n';
	else cout << "Case " << caseNumber << ": No trees." << '\n';
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int caseNumber = 0;
	while (true)
	{
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		// 초기화
		treeCount = 0;
		for (int i = 1; i <= n; i++) graph[i] = {};
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		checkTree(++caseNumber);
	}
}