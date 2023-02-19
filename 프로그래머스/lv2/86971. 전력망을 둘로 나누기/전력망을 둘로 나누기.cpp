#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<vector<int>> graph(200);

int dfs(int current, int exceptNode, int count = 1)
{
    for (int i = 0; i < graph[current].size(); i++)
    {
        int next = graph[current][i];
        if (next == exceptNode)
            continue;
        count = dfs(next, current, count + 1);
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 200;

    for (int i = 0; i < wires.size(); i++)
    {
        graph[wires[i][0]].push_back(wires[i][1]);
        graph[wires[i][1]].push_back(wires[i][0]);
    }

    for (int i = 0; i < wires.size(); i++)
    {
        int firstCount = dfs(wires[i][0], wires[i][1]);
        int secondCount = n - firstCount;
        answer = min(answer, abs(firstCount - secondCount));
    }
    return answer;
}