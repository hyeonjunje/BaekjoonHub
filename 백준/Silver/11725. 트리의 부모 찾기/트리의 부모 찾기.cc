#include<iostream>
#include<vector>

using namespace std;

vector<int> v[100001]{};

int p[100001]{};
bool visited[100001]{};

void dfs(int parent)
{
	vector<int> temp{};
	visited[parent] = true;

	
	for (int i = 0; i < v[parent].size(); i++)
	{
		if (visited[v[parent][i]] == false)
		{
			p[v[parent][i]] = parent;

			dfs(v[parent][i]);
		}
	}


}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, a, b;

	cin >> N;
	
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= N; i++) cout << p[i] << '\n';
}