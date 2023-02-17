#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int len = 10000000;
bool primeNum[10000000];

void era()
{
    for (int i = 2; i < len; i++)
        primeNum[i] = true;

    for (int i = 2; i < len; i++)
    {
        if (!primeNum[i])
            continue;

        for (int j = 2 * i; j < len; j += i)
            primeNum[j] = false;
    }
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
        //fill_n(check, 10, false);

        Reqursive(numbers, i);
        for (auto iter = subSet.begin(); iter != subSet.end(); iter++)
        {
            mainSet.insert(*iter);
        }
    }
    return mainSet;
}

int solution(string numbers) {
    int answer = 0;

    era();

    set<int> s = GetAllNumbers(numbers);

    for (auto iter = s.begin(); iter != s.end(); iter++)
    {
        if (primeNum[*iter])
        {
            answer++;
        }
    }

    return answer;
}