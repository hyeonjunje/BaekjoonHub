#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    vector<vector<int>> dp(triangle.size());

    for (int i = 0; i < triangle.size(); i++)
    {
        dp[i] = vector<int>(triangle[i].size());
    }

    dp[0][0] = triangle[0][0];

    for (int i = 1; i < triangle.size(); i++)
    {
        dp[i][0] = triangle[i][0] + dp[i - 1][0];
        dp[i][triangle[i].size() - 1] = triangle[i][triangle[i].size() - 1] + dp[i - 1][triangle[i - 1].size() - 1];

        for (int j = 1; j < triangle[i].size() - 1; j++)
        {
            dp[i][j] = max(triangle[i][j] + dp[i - 1][j - 1], triangle[i][j] + dp[i - 1][j]);
        }
    }

    for (int i = 0; i < dp[dp.size() - 1].size(); i++)
        answer = max(answer, dp[dp.size() - 1][i]);

    return answer;
}