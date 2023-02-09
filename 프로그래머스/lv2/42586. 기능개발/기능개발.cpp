#include <string>
#include <vector>
#include<iostream>
#include<math.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int endFunc = 0;

    while (endFunc != progresses.size())
    {
        int remainAmount = 100 - progresses[endFunc];

        int dayToFinish = ceil((float)remainAmount / speeds[endFunc]);

        for (int i = endFunc; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i] * dayToFinish;
        }

        int endFuncCount = 0;
        for (int i = endFunc; i < progresses.size(); i++)
        {
            if (progresses[i] >= 100)
            {
                endFuncCount++;
                endFunc++;
            }
            else
            {
                break;
            }
        }
        answer.push_back(endFuncCount);
    }

    return answer;
}
