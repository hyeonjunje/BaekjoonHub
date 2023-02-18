#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool checked[101];

int nodeCount = 1;
int dfs(vector<vector<int>> graph, int current)
{
    checked[current] = true;
    for (int i = 0; i < graph[current].size(); i++)
    {
        int next = graph[current][i];
        if (checked[next])
            continue;
        nodeCount++;
        dfs(graph, next);
    }

    return nodeCount;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 200;


    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < wires.size(); i++)
    {
        graph[wires[i][0]].push_back(wires[i][1]);
        graph[wires[i][1]].push_back(wires[i][0]);
    }


    for (int i = 0; i < wires.size(); i++)
    {
        fill_n(checked, 101, false);
        nodeCount = 1;
        checked[wires[i][1]] = true;
        int firstCount = dfs(graph, wires[i][0]);

        fill_n(checked, 101, false);
        nodeCount = 1;
        checked[wires[i][0]] = true;
        int secondCount = dfs(graph, wires[i][1]);
        //cout << firstCount << ' ' << secondCount << endl;
        answer = min(answer, abs(firstCount - secondCount));
    }

    return answer;
}