#include <string>
#include <vector>
#include <map>

using namespace std;


int solution(string word) {
    int answer = 0;

    vector<int> rule = { 0, 0, 0, 0, 1 };

    string alpha = "AEIOU";
    map<char, int> dict;
    for (int i = 0; i < alpha.size(); i++)
        dict[alpha[i]] = i;

    for (int i = rule.size() - 2; i >= 0; i--)
        rule[i] = 1 + rule[i + 1] * alpha.size();
    
    for (int i = 0; i < word.size(); i++)
    {
        answer += dict[word[i]] * rule[i] + 1;
    }

    return answer;
}