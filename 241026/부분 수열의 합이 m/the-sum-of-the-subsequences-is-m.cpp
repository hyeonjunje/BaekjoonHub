#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100
#define MAX_M 10001


int main() {
    // 여기에 코드를 작성해주세요.

    int n, m;
    int dp[MAX_M];
    int arr[MAX_N];
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    for(int i = 1; i <=m; ++i)
    {
        dp[i] = MAX_M;
    }
    dp[0] = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = m; j >0; --j)
        {
            if(j >= arr[i])
            {
                dp[j] = min(dp[j], 1 + dp[j - arr[i]]);
            }
        }
    }

    if(dp[m] == MAX_M)
    {
        cout << -1;
    }
    else
    {
        cout << dp[m];
    }
    return 0;
}