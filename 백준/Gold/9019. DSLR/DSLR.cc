#include<iostream>
#include<queue>
#include<string.h>
#include<string>

using namespace std;

const int MAX = 10000;

int A, B;
bool visited[MAX]{};

string bfs()
{
	queue<pair<int, string>> q;
	visited[A] = true;
	q.push({ A, "" });

	while (!q.empty())
	{
		int current = q.front().first;
		string ans = q.front().second;

		q.pop();

		if (current == B) return ans;

		//D
		int node = (current * 2) % MAX;
		if (visited[node] == false)
		{
			visited[node] = true;
			q.push({ node, ans + "D" });
		}

		//S
		node = current == 0 ? 9999 : current - 1;
		if (visited[node] == false)
		{
			visited[node] = true;
			q.push({ node, ans + "S" });
		}

		//L
		node = (current % 1000) * 10 + (current / 1000);
		if (visited[node] == false)
		{
			visited[node] = true;
			q.push({ node, ans + "L" });
		}

		//R
		node = (current % 10) * 1000 + (current / 10);
		if (visited[node] == false)
		{
			visited[node] = true;
			q.push({ node, ans + "R" });
		}
	}
	return "";
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

		//cout << (A % 10) * 1000 + (A / 10) << '\n';
	}
}