#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxCount = -1;

void dfs(vector<vector<int>> dungeons, int fatigue, vector<bool> checked, int count = 0)
{
    maxCount = max(maxCount, count);

    if (count == dungeons.size())
        return;

    for (int i = 0; i < dungeons.size(); i++)
    {
        if (checked[i] || fatigue < dungeons[i][0])
            continue;

        checked[i] = true;
        dfs(dungeons, fatigue - dungeons[i][1], checked, count + 1);
        checked[i] = false;
    }
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> v(dungeons.size());
    dfs(dungeons, k, v);

    return maxCount;
}