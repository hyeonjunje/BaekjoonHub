// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int N;
unordered_set<int> cache[10];
unordered_set<int> solve(int n) {
    if (!cache[n].empty()) return cache[n];
    int num = 0;
    for (int i = 0; i < n; i++) num = 10 * num + N;
    unordered_set<int> res;
    res.insert(num);
    for (int i = 1; i < n; i++) {
        int j = n - i;
        auto s1 = solve(i);
        auto s2 = solve(j);
        for (int n1 : s1) {
            for (int n2 : s2) {
                res.insert(n1 + n2);
                res.insert(n1 - n2);
                res.insert(n1 * n2);
                if (n2 != 0) res.insert(n1 / n2);
            }
        }
    }
    return cache[n] = res;
}

int solution(int _N, int number) {
    N = _N;
    for (int i = 1; i <= 8; i++) {
        solve(i);
        if (cache[i].find(number) != cache[i].end()) return i;
    }
    return -1;
}