#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<iostream>

using namespace std;

struct comp
{
	bool operator()(vector<int> a, vector<int> b)
	{
		// 소요시간 기준 오름차순 (특이한 건 b가 기준임)
        return a[1] > b[1];
		if (a[1] > b[1])
			return true;
		else if (a[1] == b[1])
			return a[0] > b[0];
		else
			return false;
	}
};

int solution(vector<vector<int>> jobs)
{
	int totalTime = 0;
	int currentTime = 0;
	int taskIndex = 0;
	sort(jobs.begin(), jobs.end());

	priority_queue<vector<int>, vector<vector<int>>, comp> pq;

	while (taskIndex < jobs.size() || !pq.empty())
	{
		if (taskIndex < jobs.size() && currentTime >= jobs[taskIndex][0])
		{
			pq.push(jobs[taskIndex]);
			taskIndex++;
			continue;
		}

		if (!pq.empty())
		{
			currentTime += pq.top()[1];
			totalTime += currentTime - pq.top()[0];
			pq.pop();
		}
		else
		{
			currentTime = jobs[taskIndex][0];
		}
	}

	totalTime /= jobs.size();
	return totalTime;
}

//#include <string>
//#include <vector>
//#include <iostream>
//#include <queue>
//#include<algorithm>
//
//using namespace std;
//
//bool comp(vector<int> a, vector<int> b)
//{
//    if (a[1] < b[1])
//        return true;
//    else if (a[1] == b[1])
//        return a[0] < b[0];
//    else
//        return false;
//}
//
//int solution(vector<vector<int>> jobs) {
//    int answer = 0;
//    int currentTime = 0;
//
//    //priority_queue<vector<int>, vector<vector<int>, compQueue> pq;
//    vector<vector<int>> v;
//    sort(jobs.begin(), jobs.end(), comp);
//
//    int index = 0;
//    while (jobs.size() != 0)
//    {
//        int minJobs = 1001;
//        int minIndex = -1;
//
//        bool check = false;
//        for (int i = 0; i < jobs.size(); i++)
//        {
//            if (currentTime < jobs[i][0])
//            {
//                if (minJobs > jobs[i][0])
//                {
//                    minJobs = jobs[i][0];
//                    minIndex = i;
//                }
//                continue;
//            }
//            else
//            {
//                check = true;
//                currentTime += jobs[i][1];
//                v.push_back(jobs[i]);
//                jobs.erase(jobs.begin() + i);
//                break;
//            }
//        }
//
//        if (!check)
//        {
//            currentTime = jobs[minIndex][0] + jobs[minIndex][1];
//            v.push_back(jobs[minIndex]);
//            jobs.erase(jobs.begin() + minIndex);
//        }
//    }
//
//    currentTime = 0;
//
//    for (int i = 0; i < v.size(); i++)
//    {
//        if (v[i][0] < currentTime)
//        {
//            answer += v[i][1] + currentTime - v[i][0];
//            currentTime += v[i][1];
//        }
//        else
//        {
//            answer += v[i][1];
//            currentTime = v[i][1] + v[i][0];
//        }
//    }
//    answer /= v.size();
//    return answer;
//}