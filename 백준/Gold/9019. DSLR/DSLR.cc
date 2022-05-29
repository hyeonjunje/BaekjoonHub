#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<string>

using namespace std;

bool visited[10000]{};
int A, B;
string bfs()
{
	queue<pair<int, string>> q;
	q.push({ A , ""});
	visited[A] = true;

	while (!q.empty())
	{
		int current = q.front().first;
		string change = q.front().second;
		q.pop();

		if (current == B) return change;

		//D
		int curNum = (2 * current) % 10000;
		if (!visited[curNum])
		{
			visited[curNum] = true;
			q.push({ curNum, change + "D" });
		}

		//S
		curNum = (current - 1) < 0 ? 9999 : current - 1;
		if (!visited[curNum])
		{
			visited[curNum] = true;
			q.push({ curNum, change + "S" });
		}

		//L
		curNum = (current % 1000) * 10 + current / 1000;
		if (!visited[curNum])
		{
			visited[curNum] = true;
			q.push({ curNum, change + "L" });
		}

		//R
		curNum = (current % 10) * 1000 + (current / 10);
		if (!visited[curNum])
		{
			visited[curNum] = true;
			q.push({ curNum, change + "R" });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		memset(visited, false, sizeof(visited));
		cin >> A >> B;

		cout << bfs() << '\n';
	}
}