#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    map<string, vector<string>> graph;
    map<string, int> check;

    words.push_back(begin);

    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            if (i == j) continue;
            int diffCount = 0;
            for (int h = 0; h < words[0].size(); h++)
                if (words[i][h] != words[j][h])
                    diffCount++;
            if (diffCount == 1)
                graph[words[i]].push_back(words[j]);
        }
        check[words[i]] = 0;
    }

    queue<string> q;
    q.push(begin);
    //check[begin] = 0;

    while (!q.empty())
    {
        string current = q.front();
        q.pop();

        if (current == target)
        {
            answer = check[current];
            break;
        }

        for (int i = 0; i < graph[current].size(); i++)
        {
            string next = graph[current][i];

            if (check[next] != 0) continue;

            check[next] = check[current] + 1;
            q.push(next);
        }
    }

    return answer;
}