#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> dp;
int arr[1001];

int binarySearch(int target)
{
    int left = 0;
    int right = dp.size() - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(dp[mid] < target)
        {
            left = mid + 1;
        }
        else if(dp[mid] == target)
        {
            return mid;
        }
        else if(dp[mid] > target)
        {
            right = mid - 1;
        }
    }
    return left;

}

void print()
{
    for(int vv : dp)
    {
        cout << vv << ' ';
    }
    cout << '\n';
}

int main() {
    // 여기에 코드를 작성해주세요.
    // 이분탐색
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    dp.push_back(arr[1]);
    for(int i = 1; i <= n; ++i)
    {
        if(dp[dp.size() - 1] < arr[i])
        {
            dp.push_back(arr[i]);
        }
        else
        {
            int index = binarySearch(arr[i]);
            dp[index] = arr[i];
        }
        //print();
    }

    cout << dp.size();
    return 0;
}