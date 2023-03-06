#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 처음이 포함됐을 때, 포함 안 됐을 때
int dp[2][1000002];

int solution(vector<int> money) {
    int answer = 0;

    dp[0][1] = money[0];
    dp[1][2] = money[1];
    dp[1][3] = max(money[1], money[2]);

    for (int i = 2; i <= money.size(); i++)
    {
        dp[0][i] = max(dp[0][i - 1], dp[0][i - 2] + money[i - 1]);
    }

    for (int i = 4; i <= money.size(); i++)
    {
        dp[1][i] = max(dp[1][i - 1], dp[1][i - 2] + money[i - 1]);
    }

    answer = max(dp[0][money.size() - 1], dp[1][money.size()]);

    return answer;
}