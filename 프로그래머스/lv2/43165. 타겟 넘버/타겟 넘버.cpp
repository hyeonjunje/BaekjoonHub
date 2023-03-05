#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dfs(vector<int> numbers, int target, int current = 0, int index = 0)
{
    if (index == numbers.size())
    {
        if (current == target)
            return 1;
        else
            return 0;
    }


    int count = 0;
    count += dfs(numbers, target, current - numbers[index], index + 1);
    count += dfs(numbers, target, current + numbers[index], index + 1);

    return count;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    answer = dfs(numbers, target);

    return answer;
}