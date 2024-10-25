#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 102
int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    cin >> n;
    int arr[MAX][MAX] = {0};
    int dp[MAX][MAX] = {0};

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = n; j > 0; --j)
        {
            if(i == 1)
            {
                dp[i][j] = arr[i][j] + dp[i][j + 1];
            }
            else if(j == n)
            {
                dp[i][j] = arr[i][j] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(arr[i][j] + dp[i - 1][j], arr[i][j] + dp[i][j + 1]);
            }
        }
    }


    cout << dp[n][1];

    return 0;
}