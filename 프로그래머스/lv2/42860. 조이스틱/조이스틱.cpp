#include <iostream>
#include <string>
#include <vector>
#include<utility>

using namespace std;

int alphaOrder[26];
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int GetOrder(char ch)
{
    for (int j = 0; j < alphabet.size(); j++)
    {
        if (ch == alphabet[j])
            return alphaOrder[j];
    }
}

int solution(string name) {
    int answer = 0;

    for (int i = 0; i <= alphabet.size() / 2; i++)
        alphaOrder[i] = i;
    for (int i = alphabet.size() / 2 + 1; i < alphabet.size(); i++)
        alphaOrder[i] = alphabet.size() - i;

    vector<pair<int, int>> aVector;  // 시작 인덱스, 끝 인덱스
    bool isStart = false;
    int startIndex, endIndex;
    for (int i = 1; i < name.size(); i++)
    {
        if (name[i] == 'A')
        {
            if (!isStart)
            {
                isStart = true;
                startIndex = i;
            }
        }
        else if (isStart)
        {
            endIndex = i - 1;
            isStart = false;
            aVector.push_back({ startIndex, endIndex });
        }
    }
    if (isStart)
    {
        aVector.push_back({ startIndex, name.size() - 1 });
    }

    for (int i = 0; i < name.size(); i++)
    {
        answer += GetOrder(name[i]);
    }

    int minValue = name.size() - 1;
    for (pair<int, int> p : aVector)
    {
        int rightAndLeft = (p.first - 1) * 2 + name.size() - p.second - 1;
        int leftAndRight = (name.size() - p.second -1) * 2 + p.first - 1;

        minValue = min(minValue, min(rightAndLeft, leftAndRight));
    }
    answer += minValue;

    return answer;
}