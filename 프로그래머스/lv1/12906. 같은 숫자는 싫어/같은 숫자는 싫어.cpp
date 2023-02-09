#include<iostream>
#include <vector>
#include<queue>

using namespace std;

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    queue<int> q;

    for (int num : arr)
    {
        if (!q.empty() && q.back() == num)
        {
            continue;
        }
        else
            q.push(num);
    }

    while (!q.empty())
    {
        int num = q.front();
        q.pop();
        answer.push_back(num);
    }

    return answer;
}
