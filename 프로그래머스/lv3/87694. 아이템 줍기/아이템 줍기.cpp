#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 최단 거리, 방향
pair<int, bool> map[102][102];
pair<int, int> dir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    for (int i = 0; i < rectangle.size(); i++)
        for (int j = 0; j < rectangle[i].size(); j++)
            rectangle[i][j] *= 2;

    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

    for (int i = 0; i < rectangle.size(); i++)
    {
        pair<int, int> startPoint = { rectangle[i][0], rectangle[i][1] };
        pair<int, int> endPoint = { rectangle[i][2], rectangle[i][3] };

        for (int x = startPoint.first; x <= endPoint.first; x++)
        {
            for (int y = startPoint.second; y <= endPoint.second; y++)
            {
                if (map[y][x].first == -1) continue;

                if (x == startPoint.first || x == endPoint.first || y == startPoint.second || y == endPoint.second)
                    map[y][x].first = 1;
                else
                    map[y][x].first = -1;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({ characterX, characterY });
    map[characterY][characterX].second = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == itemX && y == itemY)
        {
            answer = map[y][x].first / 2;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dir[i].first;
            int nextY = y + dir[i].second;

            // 범위 밖
            if (nextX < 0 || nextY < 0 || nextX > 100 || nextY > 100) continue;

            // 갈 수 없는 곳
            if (map[nextY][nextX].first == 0 || map[nextY][nextX].first == -1) continue;

            // 이미 갔던 곳
            if (map[nextY][nextX].second) continue;


            map[nextY][nextX].first = map[y][x].first + 1;
            map[nextY][nextX].second = true;

            q.push({ nextX, nextY });
        }
    }

    return answer;
}