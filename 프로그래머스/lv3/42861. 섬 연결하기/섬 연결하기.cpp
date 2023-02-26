#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[100];
bool visited[100];

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};


int solution(int n, vector<vector<int>> costs) 
{
    int answer = 0;

    for (int i = 0; i < costs.size(); i++)
    {
        graph[costs[i][0]].push_back({ costs[i][1] , costs[i][2] });
        graph[costs[i][1]].push_back({ costs[i][0] , costs[i][2] });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    for (int i = 0; i < graph[0].size(); i++)
        pq.push(graph[0][i]);
    visited[0] = true;
    int cnt = 0;

    while (cnt < n - 1)
    {
        pair<int, int> cur = pq.top();
        pq.pop();

        int node = cur.first;
        int cost = cur.second;

        if (visited[node]) continue;

        answer += cost;
        visited[node] = true;
        cnt++;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int next = graph[node][i].first;
            if (!visited[next])
                pq.push(graph[node][i]);
        }
    }
    
    return answer;
}