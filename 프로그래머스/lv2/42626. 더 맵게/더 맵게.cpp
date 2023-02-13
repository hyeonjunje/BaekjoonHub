#include <string>
#include <vector>
#include<queue>
#include<iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int> > pq;
    

    for (int sco : scoville)
        pq.push(sco);

    while (pq.top() < K)
    {
        if (pq.size() == 1)
        {
            if (pq.top() < K)
                return -1;
        }

        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        pq.push(first + second * 2);
        answer++;
    }

    return answer;
}