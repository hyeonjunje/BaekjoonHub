#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<pair<int, int>> dir = { {0, 1}, {1, 0} };

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    // 개수
    vector<vector<int>> map(n + 1);
    for (int i = 0; i < map.size(); i++)
        map[i] = vector<int>(m + 1);

    for (int i = 0; i < puddles.size(); i++)
        map[puddles[i][1]][puddles[i][0]] = { -1 };

    // m, n  좌표
    queue<pair<int, int>> q;
    q.push({ 1, 1 });
    map[1][1] = { 1 };

    while (!q.empty())
    {
        int xPos = q.front().first;
        int yPos = q.front().second;
        q.pop();

        if (xPos == m && yPos == n)
        {
            answer = map[yPos][xPos];
            break;
        }

        for (int i = 0; i < dir.size(); i++)
        {
            int nextX = xPos + dir[i].first;
            int nextY = yPos + dir[i].second;

            // 범위 밖
            if (nextX > m || nextY > n)
                continue;

            // 물 웅덩이
            if (map[nextY][nextX] == -1)
                continue;

            // 전에 갔던 곳이라면
            if (map[nextY][nextX] != 0)
            {
                map[nextY][nextX] += map[yPos][xPos] % 1000000007;
                continue;
            }
            else
                map[nextY][nextX] = map[yPos][xPos] % 1000000007;

            q.push({ nextX, nextY });
        }
    }

    return answer % 1000000007;
}