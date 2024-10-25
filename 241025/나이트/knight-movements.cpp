#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define MAX 100

int n;
int visited[MAX][MAX];
queue<pair<int, int>> q;

bool IsRange(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int x, int y)
{
    return IsRange(x, y) && visited[y][x] == 0;
}

int bfs(int targetX, int targetY)
{
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int curX = p.first;
        int curY = p.second;

        if(curX == targetX && curY == targetY)
        {
            return visited[targetY][targetX] - 1;
        }

        for(int i = 0; i < 8; ++i)
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
    cin >> n;
    int startX, startY, endX, endY;
    cin >> startY >> startX >> endY >> endX;

    visited[startY - 1][startX - 1] = 1;
    q.push({startX - 1, startY - 1});
    cout << bfs(endX - 1, endY - 1);
    return 0;
}