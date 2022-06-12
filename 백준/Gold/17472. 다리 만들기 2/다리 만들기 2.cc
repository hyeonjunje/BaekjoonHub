#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge
{
	int from, to, dist;
};

int visited[11][11];
int Map[11][11];

int N, M, Count = 0;

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };

void countIsland()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (Map[i][j] != 0 && visited[i][j] == 0)
			{
				Count++;
				Map[i][j] = Count;
				queue<pair<int, int>> q;
				q.push({ i, j });
				visited[i][j] = 1;

				while (!q.empty())
				{
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					for (int a = 0; a < 4; a++)
					{
						if (0 < x + dx[a] && 0 < y + dy[a] && M >= x + dx[a] && N >= y + dy[a] && Map[y + dy[a]][x + dx[a]] != 0 && visited[y + dy[a]][x + dx[a]] == 0)
						{
							visited[y + dy[a]][x + dx[a]] = 1;
							Map[y + dy[a]][x + dx[a]] = Count;
							q.push({ y + dy[a] , x + dx[a] });
						}
					}
				}
			}

		}
	}
}

int getDistance(int from, int to)  // 거리 반환
{
	vector<int> dist;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			
			if (Map[i][j] == from)
			{
				// 왼쪽
				int distance = 0;
				int curX = j;
				int curY = i;
				while (0 < curX - 1)
				{
					curX--;
					distance++;
					
					if (Map[i][curX] == to)
					{
						if (distance > 2) dist.push_back(distance);
						break;
					}
					if (Map[i][curX] != 0) break;
				}

				// 오른쪽
				distance = 0;
				curX = j;
				curY = i;
				while (M >= curX + 1)
				{
					curX++;
					distance++;
					
					if (Map[i][curX] == to)
					{
						if (distance > 2) dist.push_back(distance);
						break;
					}
					if (Map[i][curX] != 0) break;
				}

				// 위
				distance = 0;
				curX = j;
				curY = i;
				while (N >= curY + 1)
				{
					curY++;
					distance++;
		
					if (Map[curY][j] == to)
					{
						if(distance > 2) dist.push_back(distance);
						break;
					}
					if (Map[curY][j] != 0) break;
				}

				// 아래
				distance = 0;
				curX = j;
				curY = i;
				while (0 < curY - 1)
				{
					curY--;
					distance++;
					
					if (Map[curY][j] == to)
					{
						if (distance > 2) dist.push_back(distance);
						break;
					}
					if (Map[curY][j] != 0) break;
				}

			}
		}
	}
	if (dist.size() == 0) return -1;

	return *min_element(dist.begin(), dist.end()) - 1;
}
int parent[7]{};

int Find(int a)
{
	if (a == parent[a]) return a;
	return parent[a] = Find(parent[a]);
}

bool Union(int a, int b)
{
	a = Find(a), b = Find(b);

	if (a == b) return false;

	if (a > b) parent[a] = b;
	else parent[b] = a;
	return true;
}

bool comp(Edge a, Edge b)
{
	return a.dist < b.dist;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> Map[i][j];
		}
	}

	countIsland();
	//for (int i = 1; i <= N; i++)
	//{
	//	for (int j = 1; j <= M; j++)
	//	{
	//		cout << Map[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	for (int i = 1; i <= Count; i++)
	{
		parent[i] = i;
	}
	vector<Edge> v;
	for (int i = 1; i <= Count; i++)
	{
		for (int j = i + 1; j <= Count; j++)
		{
			int dist = getDistance(i, j);
			if(dist != -1) v.push_back({ i, j, dist });
		}
	}

	sort(v.begin(), v.end(), comp);

	int ans = 0;


	for (int i = 0; i < v.size(); i++)
	{
		//cout << v[i].from << ' ' << v[i].to << ' ' << v[i].dist << '\n';
		if (Union(v[i].from, v[i].to)) ans += v[i].dist;
	}

	int standard = Find(1);
	for (int i = 2; i <= Count; i++)
	{
		if (standard != Find(i)) { cout << -1; return 0; }
	}

	cout << ans;
}