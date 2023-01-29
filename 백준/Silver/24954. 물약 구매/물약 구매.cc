#include<iostream>
#include<vector>

using namespace std;

vector<bool> check;
vector<int> cost;
vector<vector<pair<int, int>>> discount;
vector<int> order;

int go(int index)
{
	int n = cost.size();
	
	if (index == n)
	{
		vector<int> price(cost);
		int sum = 0;
		for (int x : order)
		{
			sum += price[x];
			for (auto p : discount[x])
			{
				price[p.first] -= p.second;
				if (price[p.first] <= 0) price[p.first] = 1;
			}
		}
		return sum;
	}

	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		if (check[i]) continue;
		check[i] = true;
		order[index] = i;
		int cur = go(index + 1);
		if (ans == -1 || ans > cur) ans = cur;
		check[i] = false;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	check.resize(N);
	cost.resize(N);
	discount.resize(N);
	order.resize(N);

	for (int i = 0; i < N; i++)
		cin >> cost[i];

	for (int i = 0; i < N; i++)
	{
		int p;
		cin >> p;
		for (int j = 0; j < p; j++)
		{
			int a, d;
			cin >> a >> d;
			a -= 1;
			discount[i].push_back({ a, d });
		}
	}
	int result = go(0);
	cout << result << endl;
}