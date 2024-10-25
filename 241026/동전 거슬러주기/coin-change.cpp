#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100
#define COINMAX 10001
int main() {
    // 여기에 코드를 작성해주세요.

    int n, m;
    cin >> n >> m;

    int arr[MAX];
    int dp[COINMAX];
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    for(int i = 0; i <= m; ++i)
    {
        dp[i] = COINMAX;
    }
    dp[0] = 0;
    for(int i = 0; i <= m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i >= arr[j])
            {
                dp[i] = min(dp[i], 1 + dp[i - arr[j]]);
            }
        }
    }

    if(dp[m] == COINMAX)
    {
        cout << -1;
    }
    else
    {
        cout << dp[m];
    }

    return 0;
}