#include <string>
#include <vector>
#include <stack>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());

    stack<int> s;
    
    for (int i = 0; i < prices.size(); i++)
    {
        if (s.empty())
            s.push(i);
        else
        {
            while (prices[s.top()] > prices[i])
            {
                answer[s.top()] = i - s.top();
                s.pop();

                if (s.empty())
                    break;
            }
            s.push(i);
        }
    }
    
    while (!s.empty())
    {
        answer[s.top()] = prices.size() - s.top() - 1;
        s.pop();
    }

    return answer;
}