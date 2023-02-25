#include <iostream>
#include <string>
#include <stack>
#include<algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    stack<int> s;
    s.push(number[0] - '0');
    for (int i = 1; i < number.size(); i++)
    {
        int num = number[i] - '0';

        if (k == 0)
        {
            s.push(num);
            continue;
        }

        while (k != 0 && !s.empty() && num > s.top())
        {
            k--;
            s.pop();
        }
        s.push(num);
    }
    while (k != 0)
    {
        k--;
        s.pop();
    }

    while (!s.empty())
    {
        answer += to_string(s.top());
        s.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}