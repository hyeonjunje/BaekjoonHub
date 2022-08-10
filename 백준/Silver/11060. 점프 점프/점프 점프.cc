#include<iostream>
#include<vector>
#include<queue>
#define MAX 1001

using namespace std;

vector<int> dp[MAX];
pair<int, int> maze[MAX];  // 위치, 정수

bool isVisited[MAX];
int ans;
int N, num;

void bfs(int current)
{
	queue<pair<int, int>> q;  // 위치와 횟수
	q.push({current, 0});
	isVisited[current] = true;

	while (!q.empty())
	{
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == N)
		{
			cout << cnt;
			return;
		}

		for (int next : dp[cur])
		{
			if (!isVisited[next])
			{
				isVisited[next] = true;
				q.push({next, cnt + 1});
			}
		}
	}
	cout << -1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> num;

		maze[i] = { i, num };
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= maze[i].second; j++)
		{
			if(j + i <= N)
				dp[i].push_back(maze[j + i].first);
		}
	}

	bfs(1);
}