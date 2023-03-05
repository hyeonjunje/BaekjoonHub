#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include<set>

using namespace std;

vector<int> dp[9];

int solution(int N, int number) {
    int answer = 0;

    dp[1].push_back(N);

    for (int i = 2; i <= 8; i++)
    {
        dp[i].push_back(dp[i - 1][0] * 10 + N);
        for (int j = 1; j <= i - 1; j++)
        {
            for (int first = 0; first < dp[j].size(); first++)
            {
                for (int second = 0; second < dp[i - j].size(); second++)
                {

                    dp[i].push_back(dp[j][first] + dp[i - j][second]);
                    dp[i].push_back(dp[j][first] - dp[i - j][second]);
                    dp[i].push_back(dp[j][first] * dp[i - j][second]);
                    if (dp[i - j][second] != 0)
                        dp[i].push_back(dp[j][first] / dp[i - j][second]);
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