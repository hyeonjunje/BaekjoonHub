#include <queue>
#include <vector>
#include<iostream>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    vector<int> truck_pos(truck_weights.size());

    int next_truck = 0;
    int weightInRoad = 0;
    queue<int> road;

    road.push(0);
    weightInRoad += truck_weights[0];
    answer++;
    next_truck++;
    truck_pos[0]++;

    while (!road.empty())
    {
        if (next_truck < truck_weights.size())
        {
            // 무게가 여유 있을 때
            if (weightInRoad + truck_weights[next_truck] <= weight)
            {
                answer++;
                road.push(next_truck);
                weightInRoad += truck_weights[next_truck];

                for (int i = road.front(); i <= road.back(); i++)
                    truck_pos[i]++;

                next_truck++;

                if (truck_pos[road.front()] > bridge_length)
                {
                    weightInRoad -= truck_weights[road.front()];
                    road.pop();
                }
            }
            // 무게가 여유 없을 때
            else
            {
                int distance = bridge_length - truck_pos[road.front()] + 1;

                answer += distance;
                weightInRoad -= truck_weights[road.front()];

                for (int i = road.front(); i <= road.back(); i++)
                    truck_pos[i] += distance;

                road.pop();

                if (weightInRoad + truck_weights[next_truck] <= weight)
                {
                    road.push(next_truck);
                    weightInRoad += truck_weights[next_truck];
                    truck_pos[next_truck]++;
                    next_truck++;
                }
            }
        }
        else
        {
            answer += bridge_length - truck_pos[road.back()] + 1;

            while (!road.empty())
                road.pop();
        }
    }

    return answer;
}