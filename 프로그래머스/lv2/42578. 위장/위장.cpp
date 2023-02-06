#include<iostream>
#include <string>
#include <set>
#include<vector>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<string> clothType;
unordered_map<string, int> clothsMap;

int answer = 0;

void dfs(int count, int startIndex = 0, vector<string> comb = {})
{
    if (comb.size() == count)
    {
        int temp = 1;
        for (string s : comb)
        {
            temp *= clothsMap[s];
        }
        answer += temp;
        return;
    }

    for (int i = startIndex; i < clothType.size(); i++)
    {
        comb.push_back(clothType[i]);

        dfs(count, i + 1, comb);

        for (int index = 0; index < comb.size(); index++)
        {
            if (comb[index] == clothType[i])
            {
                comb.erase(comb.begin() + index);
                break;
            }
        }
    }
}

int solution(vector<vector<string>> clothes) {
    int result = 0;

    set<string> s;
    for (vector<string> v : clothes)
    {
        s.insert(v[1]);
        clothsMap[v[1]]++;
    }

    for (auto iter = s.begin(); iter != s.end(); iter++)
        clothType.push_back(*iter);

    if (clothType.size() == clothes.size())
        return pow(2, clothes.size()) - 1;

    for (int i = 1; i <= clothType.size(); i++)
    {
        answer = 0;
        dfs(i);
        result += answer;
    }

    return result;
}
