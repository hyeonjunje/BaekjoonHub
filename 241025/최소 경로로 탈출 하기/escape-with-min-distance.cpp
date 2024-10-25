#include <iostream>
#include<queue>
#include<utility>
using namespace std;
#define MAX 100

int n, m;
int visited[MAX][MAX];
int arr[MAX][MAX];

bool IsRange(int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n;
}

bool CanGo(int x, int y)
{
    return IsRange(x, y) && visited[y][x] == 0 && arr[y][x] == 1;
}

int bfs(int x, int y)
{
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = 1;
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int curX = p.first;
        int curY = p.second;

        if(curX == m - 1 && curY == n - 1)
        {
            return visited[curY][curX] - 1;
        }

        for(int i = 0; i < 4; ++i)
        {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if(CanGo(nextX, nextY))
            {
                visited[nextY][nextX] = visited[curY][curX] + 1;
                q.push({nextX, nextY});
            }
        }

    }

    return -1;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
        }
    }
    
    cout << bfs(0, 0);
    return 0;
}