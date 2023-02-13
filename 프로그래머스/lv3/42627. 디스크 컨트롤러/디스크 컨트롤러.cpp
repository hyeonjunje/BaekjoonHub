#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include<algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    if (a[1] < b[1])
        return true;
    else if (a[1] == b[1])
        return a[0] < b[0];
    else
        return false;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int currentTime = 0;

    //priority_queue<vector<int>, vector<vector<int>, compQueue> pq;
    vector<vector<int>> v;
    sort(jobs.begin(), jobs.end(), comp);

    int index = 0;
    while (jobs.size() != 0)
    {
        int minJobs = 1001;
        int minIndex = -1;

        bool check = false;
        for (int i = 0; i < jobs.size(); i++)
        {
            if (currentTime < jobs[i][0])
            {
                if (minJobs > jobs[i][0])
                {
                    minJobs = jobs[i][0];
                    minIndex = i;
                }
                continue;
            }
            else
            {
                check = true;
                currentTime += jobs[i][1];
                v.push_back(jobs[i]);
                jobs.erase(jobs.begin() + i);
                break;
            }
        }

        if (!check)
        {
            currentTime = jobs[minIndex][0] + jobs[minIndex][1];
            v.push_back(jobs[minIndex]);
            jobs.erase(jobs.begin() + minIndex);
        }
    }

    currentTime = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i][0] < currentTime)
        {
            answer += v[i][1] + currentTime - v[i][0];
            currentTime += v[i][1];
        }
        else
        {
            answer += v[i][1];
            currentTime = v[i][1] + v[i][0];
        }
    }
    answer /= v.size();
    return answer;
}