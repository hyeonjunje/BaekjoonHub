#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include<set>

using namespace std;

set<int> dp[9];

int solution(int N, int number) {
    int answer = 0;

    dp[1].insert(N);

    for (int i = 2; i <= 8; i++)
    {
        int n = 0;
        for (int temp = 0; temp < i; temp++) n = 10 * n + N;
        dp[i].insert(n);
        for (int j = 1; j <= i - 1; j++)
        {
            for (int first : dp[j])
            {
                for (int second : dp[i - j])
                {
                    dp[i].insert(first + second);
                    dp[i].insert(first - second);
                    dp[i].insert(first * second);
                    if(second != 0)
                        dp[i].insert(first / second);
                }
            }
        }
    }

    for (int i = 1; i <= 8; i++)
    {
        for (int num : dp[i])
            if (num == number)
                return i;
    }
    return -1;
}
