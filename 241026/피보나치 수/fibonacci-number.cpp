#include <iostream>
using namespace std;
#define MAX 46

int memo[MAX]={-1};

int fibo(int n)
{
    if(memo[n] != -1)
    {
        return memo[n];
    }

    for(int i = 3; i <= n; ++i)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    cin >> n;
    memo[0]=0;
    memo[1]=1;
    memo[2]=1;
    cout << fibo(n);

    return 0;
}