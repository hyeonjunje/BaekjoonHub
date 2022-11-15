#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {

    if(s.size() == 1)
        return 1;
    
    int offset = s.size() / 2;

    int start = 0;

    int answer = 1001;

    for (int i = offset; i > 0; i--)
    {
        start = 0;
        string s1 = "";
        int subAns = i;

        bool isSame = false;
        int count = 1;
        while (start + i <= s.size() + i)
        {
            if (s1 != "")
            {
                if (s1 == s.substr(start, i))
                {
                    count++;
                    if (!isSame)
                    {
                        subAns += 1;
                        isSame = true;
                    }
                }
                else
                {
                    subAns += to_string(count).size() - 1;
                    count = 1;

                    subAns += s.substr(start, i).size();
                    isSame = false;
                }
            }
            s1 = s.substr(start, i);

            start += i;
        }

        answer = min(answer, subAns);
    }

    return answer;
}
