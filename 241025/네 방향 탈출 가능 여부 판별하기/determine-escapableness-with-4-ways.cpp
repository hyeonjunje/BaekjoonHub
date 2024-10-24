#include <iostream>
#include <utility>
#include <queue>

using namespace std;
#define MAX 100

int n, m;
int arr[MAX][MAX];
bool visited[MAX][MAX];



bool CanGo(int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n;
}

int bfs(pair<int, int> p)
{
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    queue<pair<int, int>> q;
    q.push(p);
    visited[p.second][p.first] = true;
    while(!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();

        if(current.first == m - 1 && current.second == n - 1)
        {
            return 1;
        }

        for(int i = 0; i < 4; ++i)
        {
            int nextX = current.first + dx[i];
            int nextY = current.second + dy[i];

            if(!CanGo(nextX, nextY))
            {
                continue;
            }

            if(visited[nextY][nextX])
            {
                continue;
            }

            if(arr[nextY][nextX] == 0)
            {
                continue;
            }

            visited[current.second][current.first] = true;
            q.push({nextX, nextY});
        }
    }

    return 0;
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j <m; ++j)
        {
            cin >> arr[i][j];
        }
    }

    cout << bfs({0, 0});
    return 0;
}