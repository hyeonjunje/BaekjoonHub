#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;


int edge[10001][10001];
map<string, int> node;
vector<string> graph[10001];
vector<string> v;


bool dfs(int current, int targetCount, int count = 0)
{
    if (targetCount == count)
        return true;

    for (int i = 0; i < graph[current].size(); i++)
    {
        int next = node[graph[current][i]];
        if (edge[current][next] != 0)
        {
            edge[current][next]--;
            v.push_back(graph[current][i]);
            bool flag = dfs(next, targetCount, count + 1);
            if (flag == false)
            {
                edge[current][next]++;
                v.erase(v.end() - 1);
            }
            else
                return true;
        }
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {

    int count = 0;
    for (int i = 0; i < tickets.size(); i++)
    {
        if (node.count(tickets[i][0]) == 0)
            node[tickets[i][0]] = count++;
        if (node.count(tickets[i][1]) == 0)
            node[tickets[i][1]] = count++;

        graph[node[tickets[i][0]]].push_back(tickets[i][1]);
        edge[node[tickets[i][0]]][node[tickets[i][1]]]++;
    }

    for (int i = 0; i < 10001; i++)
        sort(graph[i].begin(), graph[i].end());

    v.push_back("ICN");
    dfs(node["ICN"], tickets.size());

    return v;
}