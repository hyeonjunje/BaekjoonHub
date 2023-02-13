#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer = {0, 0};

    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;

    for(string s : operations)
    {
        char oper = s[0];
        int num = stoi(s.substr(2, s.size() - 2));
        if (oper == 'I')
        {
            minHeap.push(num);
            maxHeap.push(num);
        }
        else
        {
            if (!maxHeap.empty() && !minHeap.empty())
            {
                if (num == 1)
                {
                    maxHeap.pop();
                }
                else
                {
                    minHeap.pop();
                }
            }
        }

        answer[0] = maxHeap.empty() ? INT_MIN : maxHeap.top();
        answer[1] = minHeap.empty() ? INT_MAX : minHeap.top();

        if (answer[0] < answer[1])
        {
            while (!minHeap.empty())
                minHeap.pop();
            while (!maxHeap.empty())
                maxHeap.pop();
            answer = { 0, 0 };
        }
    }

    return answer;
}