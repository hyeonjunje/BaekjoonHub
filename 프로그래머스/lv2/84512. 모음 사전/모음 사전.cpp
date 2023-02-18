#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<string> dic;
string alpha = "AEIOU";

void dfs(string word = "")
{
    if (word.size() >= 5)
        return;

    for (int i = 0; i < alpha.size(); i++)
    {
        word += alpha[i];
        dic.push_back(word);
        dfs(word);

        word = word.substr(0, word.size() - 1);
    }
}

int solution(string word) {
    int answer = 0;

    dfs();

    for (int i = 0; i < dic.size(); i++)
    {
        if (dic[i] == word)
        {
            answer = i + 1;
            break;
        }
    }
    return answer;
}