#include <vector>
#include<map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    map<int, int> tmp;

    for (int num : nums)
        tmp[num]++;

    return min(nums.size() / 2, tmp.size());
}