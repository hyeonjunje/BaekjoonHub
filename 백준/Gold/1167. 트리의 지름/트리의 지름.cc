#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int>> v[100001]{};

bool visited[100001]{};

int ans = 0;
int fallAwayPoint;
void dfs(int parent, int fAns)
{
	visited[parent] = true;

	for (int i = 0; i < v[parent].size(); i++)
	{
		if (visited[v[parent][i].first] == false)
		{
			if (ans < fAns + v[parent][i].second)
			{
				ans = fAns + v[parent][i].second;
				fallAwayPoint = v[parent][i].first;
			}
			dfs(v[parent][i].first, fAns + v[parent][i].second);

		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, a;

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		vector<int> tempV;
		while (true)
		{
			cin >> a;

			if (a == -1) break;

			tempV.push_back(a);
		}
		for (int j = 1; j < tempV.size(); j += 2)
		{
			v[tempV[0]].push_back({ tempV[j], tempV[j + 1] });
		}
	}


	dfs(1, 0);
	for (int i = 1; i <= N; i++) visited[i] = false;
	dfs(fallAwayPoint, 0);

	cout << ans;
}