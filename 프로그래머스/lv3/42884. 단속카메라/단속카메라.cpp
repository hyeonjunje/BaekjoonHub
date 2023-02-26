#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool tmp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.begin(), routes.end(), tmp);

    int count = 0;
    while (count < routes.size())
    {
        int lastPos = routes[count][1];
        int temp = count;
        for (int i = temp; i < routes.size(); i++)
        {
            if (routes[i][0] <= lastPos && lastPos <= routes[i][1])
                count++;
            else
                break;
        }
        answer++;
    }

    return answer;
}