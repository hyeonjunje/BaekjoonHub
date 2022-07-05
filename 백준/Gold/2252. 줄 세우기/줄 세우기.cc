#include<vector>
#include<iostream>
#include<stack>

using namespace std;

int N, M;
vector<int> graph[32001];
stack<int> s;
bool visited[32001];

void dfs(int current)
{
	if (visited[current]) return;

	visited[current] = true;

	for (int i = 0; i < graph[current].size(); i++)
	{
		int next = graph[current][i];
		if (visited[next]) continue;
		dfs(next);
	}
	s.push(current);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;

		graph[a].push_back(b);
	}
	for (int i = 1; i <= N; i++)
	{
		dfs(i);
	}
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}

}