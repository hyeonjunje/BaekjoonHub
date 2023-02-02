#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int i, int j)
{
	return i > j;
}


int main()
{
	int N, k, x;

	vector<int> vec;
	cin >> N >> k;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		vec.push_back(x);
	}

	sort(vec.begin(), vec.end(), compare);

	cout << vec[k - 1];
}