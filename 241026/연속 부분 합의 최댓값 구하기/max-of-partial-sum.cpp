#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000
int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    int arr[MAX]{0};
    int dp[MAX]{0};
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n; ++i)
    {
        dp[i] = -1001;
    }

    dp[0] = arr[0];
    for(int i = 1; i < n; ++i)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    }

    int result = -1001;
    for(int i = 0; i < n; ++i)
    {
        result = max(result, dp[i]);
    }
    cout << result;

    return 0;
}