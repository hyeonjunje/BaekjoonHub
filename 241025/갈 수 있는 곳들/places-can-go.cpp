#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 100

int n, k;
int arr[MAX][MAX] = {0};
bool visited[MAX][MAX] = {false};

bool CanGo(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

int bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});

    visited[y][x] = true;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    int result = 1; 
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int xx = p.first;
        int yy = p.second;
        for(int i = 0; i < 4; ++i)
        {
            int nextX = xx + dx[i];
            int nextY = yy + dy[i];

            if(!CanGo(nextX, nextY))
            {
                continue;
            }
            if(arr[nextY][nextX] == 1)
            {
                continue;
            }
            if(visited[nextY][nextX])
            {
                continue;
            }

            visited[nextY][nextX] = true;
            result++;
            q.push({nextX, nextY});
        }
    }
    return result;
}

int main() {
    // 여기에 코드를 작성해주세요.

    int result = 0;
    cin >> n >> k;
    int x, y;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < k; ++i)
    {
        cin >> x >> y;
        if(arr[y - 1][x - 1] == 0 && !visited[y - 1][x - 1])
        {
            result += bfs(0, 0);
        }
    }

    cout << result;

    return 0;
}