#include<iostream>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;

int N, K;

vector<int> v;

int visited[200001]{};
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = 0;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		if (current == K) return;


		if (current > 0 && visited[current - 1] == -1) { q.push(current - 1); visited[current - 1] = visited[current] + 1; }
		if (current < 100000 && visited[current + 1] == -1) { q.push(current + 1); visited[current + 1] = visited[current] + 1; }
		if (current < 100000 && visited[current * 2] == -1) { q.push(current * 2); visited[current * 2] = visited[current] + 1; }
	}
}

void backtracking(int end)
{
	v.push_back(end);
	int current = end;
	while (current != N)
	{
		if (current - 1 >= 0 && visited[current - 1] == visited[current] - 1) { current = current - 1; v.push_back(current); }
		else if (current + 1 <= 100000 && visited[current + 1] == visited[current] - 1) { current = current + 1; v.push_back(current); }
		else if ((current % 2 == 0) && visited[current / 2] == visited[current] - 1) { current = current / 2; v.push_back(current); }
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	memset(visited, -1, sizeof(visited));

	bfs(N);
	backtracking(K);
	cout << visited[K] << '\n';
	for (int i = v.size() - 1; i != -1; i--) cout << v[i] << ' ';
}