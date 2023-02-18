#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int i = 1; i <= yellow; i++)
    {
        // 나누어 떨어지면 실행
        if (yellow % i == 0)
        {
            int hor = yellow / i;
            int ver = i;
            int myBrown = (hor + 2) * 2 + (ver * 2);
            if (myBrown == brown)
            {
                answer = { hor + 2, ver + 2 };
                break;
            }
        }
    }
    return answer;
}