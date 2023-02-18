#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

bool isPrime(int number)
{
    if (number == 1)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;

    bool isPrime = true;
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
            return false;
    }

    return isPrime;
}


int solution(string numbers) {
    int answer = 0;

    vector<int> numbersVec;
    for (char ch : numbers)
        numbersVec.push_back(ch - '0');

    sort(numbersVec.begin(), numbersVec.end());
    
    set<int> s;
    do
    {
        string num = "";
        for (int i = 0; i < numbersVec.size(); i++)
        {
            num += to_string(numbersVec[i]);
            s.insert(stoi(num));
        }
    } while (next_permutation(numbersVec.begin(), numbersVec.end()));

    for (auto iter = s.begin(); iter != s.end(); iter++)
    {
        if (isPrime(*iter))
            answer++;
    }

    return answer;
}