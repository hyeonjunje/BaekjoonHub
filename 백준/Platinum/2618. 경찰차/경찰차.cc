#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

vector<pair<int, int>> pathA;
vector<pair<int, int>> pathB;

int N, W, x, y;

int cache[1001][1001]{};

int getMinDistance(int A, int B)
{
	if (A == W || B == W) return 0;

	int& ret = cache[A][B];

	if (cache[A][B] != -1) return ret;

	int maxLocation = max(A, B) + 1;

	int distA = abs(pathA[maxLocation].first - pathA[A].first) + abs(pathA[maxLocation].second - pathA[A].second);
	int distB = abs(pathB[maxLocation].first - pathB[B].first) + abs(pathB[maxLocation].second - pathB[B].second);

	int ret1 = getMinDistance(maxLocation, B) + distA;
	int ret2 = getMinDistance(A, maxLocation) + distB;

	return ret = min(ret1, ret2);
}

void orderNum(int A, int B)
{
	if (A == W || B == W) return;

	int maxLocation = max(A, B) + 1;

	int distA = abs(pathA[maxLocation].first - pathA[A].first) + abs(pathA[maxLocation].second - pathA[A].second);
	int distB = abs(pathB[maxLocation].first - pathB[B].first) + abs(pathB[maxLocation].second - pathB[B].second);

	int ret1 = getMinDistance(maxLocation, B) + distA;
	int ret2 = getMinDistance(A, maxLocation) + distB;

	if (ret1 < ret2)
	{
		cout << "1" << '\n';
		orderNum(maxLocation, B);
	}
	else
	{
		cout << "2" << '\n';
		orderNum(A, maxLocation);
	}	
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> W;

	memset(cache, -1, sizeof(cache));

	pathA.push_back({ 1,1 });
	pathB.push_back({ N,N });

	for (int i = 0; i < W; i++)
	{
		cin >> x >> y;
		pathA.push_back({ x, y });
		pathB.push_back({ x, y });
	}
	cout << getMinDistance(0, 0) << '\n';
	orderNum(0, 0);
}