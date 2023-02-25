#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = people.size();

    sort(people.begin(), people.end());

    int canMoveDouble = 0;

    int startIndex = 0;
    int endIndex = people.size() - 1;
    while (startIndex < endIndex)
    {
        // 2명 태울 수 있으면
        if (people[startIndex] + people[endIndex] <= limit)
        {
            startIndex++;
            endIndex--;
            answer--;
        }
        else
        {
            endIndex--;
        }
    }

    return answer;
}