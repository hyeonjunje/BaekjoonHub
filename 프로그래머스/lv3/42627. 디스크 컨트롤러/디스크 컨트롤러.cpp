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