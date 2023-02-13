#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;


int solution(vector<int> citations) {
    int answer = 0;
    int minHIndex = -1;
    sort(citations.begin(), citations.end());

    for (int i = 0; i < citations.size(); i++)
    {
        int citationCount = citations[i];
        int lowerCount = i;
        int upperCount = citations.size() - i;

        if (lowerCount <= citationCount && upperCount >= citationCount)
        {
            minHIndex = i;
            answer = citations[minHIndex];
        }
        else
            break;
    }

    if (minHIndex != -1)
    {
        for (int citationCount = citations[minHIndex] + 1; citationCount < citations[minHIndex + 1]; citationCount++)
        {
            int upperH = citations.size() - minHIndex - 1;
            if (citationCount <= upperH)
                answer = citationCount;
        }
    }
    else
    {
        for (int citationCount = 0; citationCount < citations[0]; citationCount++)
        {
            int upperH = citations.size() - minHIndex - 1;
            if (citationCount <= upperH)
                answer = citationCount;
        }
    }
    
    return answer;
}