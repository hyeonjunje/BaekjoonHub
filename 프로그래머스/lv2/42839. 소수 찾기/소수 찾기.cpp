#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include<cmath>

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

set<int> subSet;

bool check[10];

void Reqursive(string numbers, int length, int currentIndex = -1, string currentNumber = "")
{
    if (currentNumber.size() == length)
    {
        subSet.insert(stoi(currentNumber));
        return;
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        if (check[i]) continue;

        currentNumber += numbers[i];
        check[i] = true;
        Reqursive(numbers, length, i, currentNumber);
        check[i] = false;
        currentNumber = currentNumber.substr(0, currentNumber.size() - 1);
    }
}

set<int> GetAllNumbers(string numbers)
{
    set<int> mainSet;
    for (int i = 1; i <= numbers.length(); i++)
    {
        subSet.clear();

        Reqursive(numbers, i);
        for (auto iter = subSet.begin(); iter != subSet.end(); iter++)
            mainSet.insert(*iter);
    }
    return mainSet;
}

int solution(string numbers) {
    int answer = 0;

    set<int> s = GetAllNumbers(numbers);

    for (auto iter = s.begin(); iter != s.end(); iter++)
        if (isPrime(*iter))
            answer++;

    return answer;
}