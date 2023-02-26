#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

bool comp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int findParent(int idx)
{
    if (parent[idx] == idx)
        return idx;

    return parent[idx] = findParent(parent[idx]);
}

int solution(int n, vector<vector<int>> costs) 
{
    int ans = 0;

    for (int i = 0; i < n; i++)
        parent.push_back(i);

    sort(costs.begin(), costs.end(), comp);

    for (int i = 0; i < costs.size(); i++)
    {
        int start = findParent(costs[i][0]);
        int end = findParent(costs[i][1]);
        int cost = costs[i][2];

        if (start != end)
        {
            ans += cost;
            parent[end] = start;
        }
    }
    
    return ans;
}