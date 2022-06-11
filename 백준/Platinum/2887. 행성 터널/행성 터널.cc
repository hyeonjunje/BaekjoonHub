#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

//using namespace std;

int parent[100001]{};

std::vector<std::pair<int, int>> X;
std::vector<std::pair<int, int>> Y;
std::vector<std::pair<int, int>> Z;

std::vector<std::tuple<int, int, int>> v;

int Find(int a)
{
	if (a == parent[a]) return a;
	return parent[a] = Find(parent[a]);
}

bool Union(int a, int b)
{
	a = Find(a), b = Find(b);

	if (a == b) return false;

	if (a < b) parent[b] = a;
	else parent[a] = b;
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N, a, b, c;
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;

		std::cin >> a >> b >> c;
		X.push_back({ a, i });
		Y.push_back({ b, i });
		Z.push_back({ c, i });
	}
	
	std::sort(X.begin(), X.end());
	std::sort(Y.begin(), Y.end());
	std::sort(Z.begin(), Z.end());

	for (int i = 0; i < N - 1; i++)
	{
		v.push_back({ X[i + 1].first - X[i].first, X[i + 1].second,  X[i].second });
		v.push_back({ Y[i + 1].first - Y[i].first, Y[i + 1].second,  Y[i].second });
		v.push_back({ Z[i + 1].first - Z[i].first, Z[i + 1].second,  Z[i].second });
	}
	std::sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (Union(std::get<1>(v[i]), std::get<2>(v[i]))) ans += std::get<0>(v[i]);
	}
	std::cout << ans;
}