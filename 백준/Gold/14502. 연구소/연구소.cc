#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int map[9][9]{};
int temp[9][9]{};
vector<pair<int, int>> pos;
vector<pair<int, int>> virusPos;
vector<int> ans;
int N, M;

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };

void init()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			temp[i][j] = map[i][j];
		}
	}
}

void bfs()
{
	queue<pair<int, int>> q;
	for (auto p : virusPos)
	{
		q.push({ p });
	}

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			if (y + dy[i] > 0 && y + dy[i] <= N && x + dx[i] > 0 && x + dx[i] <= M  && temp[y + dy[i]][x + dx[i]] == 0)
			{
				temp[y + dy[i]][x + dx[i]] = 2;
				q.push({ y + dy[i], x + dx[i] });
			}
		}
	}
}

int checkSafe()
{
	int count = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (temp[i][j] == 0) count++;
		}
	}
	return count;
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] == 0) pos.push_back({ i, j });
			if (map[i][j] == 2)  virusPos.push_back({ i, j });
		}
	}

	for (int i = 0; i < pos.size() - 2; i++)
	{
		for (int j = i + 1; j < pos.size() - 1; j++)
		{
			for (int h = j + 1; h < pos.size(); h++)
			{
				init();
				temp[pos[i].first][pos[i].second] = 1;
				temp[pos[j].first][pos[j].second] = 1;
				temp[pos[h].first][pos[h].second] = 1;

				bfs();
				ans.push_back(checkSafe());
			}
		}
	}

	cout << *max_element(ans.begin(), ans.end());
}