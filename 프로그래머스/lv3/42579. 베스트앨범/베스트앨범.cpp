#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

bool comp2(pair<string, vector<pair<int, int>>> a, pair<string, vector<pair<int, int>>> b)
{
    int sumA = 0, sumB = 0;

    for (int i = 0; i < a.second.size(); i++)
    {
        sumA += a.second[i].second;
    }
    for (int i = 0; i < b.second.size(); i++)
    {
        sumB += b.second[i].second;
    }

    return sumA > sumB;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    // 키는 장르, 값은 인덱스와 재생수
    unordered_map<string, vector<pair<int, int>>> map;

    for (int i = 0; i < genres.size(); i++)
        map[genres[i]].push_back({ i, plays[i] });

    vector<pair<string, vector<pair<int, int>>>> v (map.begin(), map.end());

    sort(v.begin(), v.end(), comp2);

    for (int i = 0; i < v.size(); i++)
    {
        sort(v[i].second.begin(), v[i].second.end(), comp);
    }

    for (int i = 0; i < v.size(); i++)
    {
        answer.push_back(v[i].second[0].first);
        if (v[i].second.size() >= 2)
            answer.push_back(v[i].second[1].first);
    }

    return answer;
}