#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> dir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int solution(vector<vector<int> > maps)
{
    int answer = -1;

    vector<vector<int>> map(maps.size(), vector<int>(maps[0].size()));

    for (int i = 0; i < maps.size(); i++)
        for (int j = 0; j < maps[i].size(); j++)
            if (maps[i][j] == 0)
                map[i][j] = -1;

    queue<pair<int, int>> q;
    
    q.push({ 0, 0 });
    map[0][0] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == maps[0].size() - 1 && y == maps.size() - 1)
        {
            answer = map[y][x];
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dir[i].first;
            int nextY = y + dir[i].second;

            // 범위 밖
            if (nextY < 0 || nextX < 0 || nextY >= maps.size() || nextX >= maps[0].size()) continue;

            // 벽일 때
            if (maps[nextY][nextX] == -1) continue;

            if (map[nextY][nextX] == 0)
            {
                map[nextY][nextX] = map[y][x] + 1;
                q.push({ nextX, nextY });
            }
        }
    }

    return answer;
}