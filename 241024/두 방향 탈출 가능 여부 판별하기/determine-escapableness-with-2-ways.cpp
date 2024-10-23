#include <iostream>
using namespace std;

int n, m;
int maze[100][100];
bool visited[100][100];

int result = 0;

int dx[2] = {0, 1};
int dy[2] = {1, 0}; 

void dfs(int x, int y)
{
    if(x == m - 1 && y == n - 1)
    {
        result = 1;
    }

    for(int i = 0; i < 2; ++i)
    {
        int curX = x + dx[i];
        int curY = y + dy[i];

        if(curY >= n || curX >= m)
        {
            continue;
        }

        if(maze[curY][curX] == 0)
        {
            continue;
        }

        if(!visited[curY][curX])
        {
            visited[curY][curX] = true;
            dfs(curX, curY);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> maze[i][j];
        }
    }

    visited[0][0] = true;
    dfs(0, 0);
    cout << result;
    return 0;
}