#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[25][25];
bool visited[25][25];

vector<int> v;
int maxValue = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool IsRange(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < n;
}

void dfs(int x, int y)
{
    for(int i = 0; i < 4; ++i)
    {
        int curX = x + dx[i];
        int curY = y + dy[i];

        if(!IsRange(curX, curY))
        {
            continue;
        }

        if(visited[curY][curX])
        {
            continue;
        }

        if(arr[curY][curX] == 0)
        {
            continue;
        }

        visited[curY][curX] = true;
        dfs(curX, curY);
        maxValue++;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(arr[i][j] == 1 && !visited[i][j])
            {
                maxValue = 1;
                visited[i][j] = true;
                dfs(j, i);
                v.push_back(maxValue);
            }
        }
    }
    sort(v.begin(), v.end());

    cout << v.size() << '\n';
    for(int ss : v)
    {
        cout << ss << '\n';
    }
    return 0;
}