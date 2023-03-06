#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> graph[201];
bool check[201];

bool dfs(int current)
{
    if (check[current] == true)
        return false;

    check[current] = true;

    for (int i = 0; i < graph[current].size(); i++)
    {
        int next = graph[current][i];
        if (check[next] == false)
            dfs(next);
    }
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < computers.size(); i++)
    {
        for (int j = 0; j < computers[i].size(); j++)
        {
            if (i == j) continue;
            if (computers[i][j] == 1)
                graph[i].push_back(j);
        }
    }

    for (int i = 0; i < n; i++)
        if (dfs(i))
            answer++;

    return answer;
}