#include <iostream>
using namespace std;
#define MAX 1001


int main() {
    // 여기에 코드를 작성해주세요.

    int n; 
    cin >> n;
    int arr[MAX];

    arr[2] = 1;
    arr[3] = 1;
    for(int i = 4; i <= n; ++i)
    {
        arr[n] = arr[n - 2] + arr[n - 3];
        arr[n] %= 10007;
    }
    cout << arr[n];

    return 0;
}