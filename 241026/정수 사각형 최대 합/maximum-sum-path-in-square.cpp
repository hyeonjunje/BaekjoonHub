#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101;

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    cin >> n;
    int arr[101][101]= {0};
    int dp[101][101] = {0};

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            dp[i][j] = max(arr[i][j] + dp[i - 1][j], arr[i][j] + dp[i][j - 1]);
        }
    }


    cout << dp[n][n];


    return 0;
}