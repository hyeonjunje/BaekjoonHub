#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>

using namespace std;

#define EAST 1
#define WEST 2
#define SOUTH 3
#define NORTH 4

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int K;
	cin >> K;

	queue<pair<int, int>> q;

	int dirArr[5] = {};

	int dir, distance;
	int maxHorDir, maxVerDir, maxHorDis, maxVerDis;
	for (int i = 0; i < 6; i++)
	{
		cin >> dir >> distance;

		q.push({ dir, distance });
		dirArr[dir]++;
	}
	for (int i = 1; i < 5; i++)
	{
		if (dirArr[i] == 1 && 1 <= i && i < 3) maxHorDir = i;
		if (dirArr[i] == 1 && 3 <= i && i < 5) maxVerDir = i;
	}


	for (int i = 0; i < 6; i++)
	{
		if (q.front().first != maxHorDir)
		{
			auto cur = q.front();
			q.pop();
			q.push(cur);
		}
	}

	int order = 0;
	int minHorDir = maxHorDir == EAST ? WEST : EAST;
	int minVerDir = maxVerDir == SOUTH ? NORTH : SOUTH;
	int subHorDir, subVerDir;
	for (int i = 0; i < 6; i++)
	{
		if (q.front().first == maxHorDir)
		{
			maxHorDis = q.front().second;
		}
		else if (q.front().first == maxVerDir)
		{
			maxVerDis = q.front().second;
		}
		else if (q.front().first == minHorDir)
		{
			if (order >= 1 && order <= 2)
			{
				subHorDir = q.front().second;
			}
			order++;
		}
		else if (q.front().first == minVerDir)
		{
			if (order >= 1 && order <= 2)
			{
				subVerDir = q.front().second;
			}
			order++;
		}
		q.pop();
	}
	cout << (maxHorDis * maxVerDis - subHorDir * subVerDir) * K;
}