#include <iostream>
#include <algorithm>
#include<string>
#include<math.h>
using namespace std;

int n, k;

int w[15];
string tmp[15];
int Size[15];
int ten[51];
// dp[i][j] : i는 상태(집합) 숫자를 무엇을 사용한지 비트로 표현,  j는 i의 상태로 이루어진 숫자를 k로 나누었을 때 나머지가 j가 되는 개수
long long dp[1 << 15][101];

long long GCD(long long a, long long b)
{
    if (b == 0) return a;
    return GCD(b, a % b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> tmp[i];
        Size[i] = tmp[i].size();
    }

    cin >> k;

    // 나머지 연산을 코드화
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < Size[i]; j++)
        {
            w[i] = ((tmp[i][j] - '0') + w[i] * 10) % k;
        }
    }

    // 10의 0승을 k로 나머지 하면 1임
    ten[0] = 1;
    for (int i = 1; i <= 50; i++)
    {
        ten[i] = (ten[i - 1] * 10) % k;
    }

    // 0을 k로 나눈 나머지가 0인 개수는 1개임
    dp[0][0] = 1;

    // 상태
    for (int i = 0; i < (1 << n); i++)
    {
        // 나머지가 되는 수   
        for (int j = 0; j < k; j++)
        {
            // 몇번째 수 사용할지
            for (int t = 0; t < n; t++)
            {
                // 이미 골랐던 수가 아니라면
                if (!(i & 1 << t))
                {
                     //현재 집합이 i이고 나머지가 j일 때, i에 속하지 않은 t번 수를 뒤에 이어붙였을 때 나머지를 next라고 하면
                     //dp[i | 1 << t][next] += dp[i][j]
                     // 
                     //   next = (새로만들어진 수) % k
                     //   = (원래 수 * pow(10, len(l번째 수)) + l번째 수) % k
                     //   = [(원래 수 * pow(10, len(l번째 수))) % k + l번째 수 % k] % k
                     //   = [(원래 수 % k * pow(10, len(l번째 수)) % k) % k + l번째 수 % k] % k  
                     //   = [(j * pow(10, len(l번째 수)) % k) % k + l번째 수 % k] % k

                    int next = ((j * ten[Size[t]]) % k + w[t]) % k;
                    dp[i | 1 << t][next] += dp[i][j];
                }
            }
        }
    }

    long long Count = dp[(1 << n) - 1][0];
    long long All = 1;
    for (int i = n; i > 0; i--) All *= i;
    long long gcd = GCD(All, Count);
    cout << Count / gcd << '/' << All / gcd;
}