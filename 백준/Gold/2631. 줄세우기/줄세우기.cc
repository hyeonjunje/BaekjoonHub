#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 201
using namespace std;

int num[MAX];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> v;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	v.push_back(num[1]);
	for (int i = 2; i <= N; i++)
	{
		if (v.back() < num[i])
		{
			v.push_back(num[i]);
		}
		else
		{
			int pos = lower_bound(v.begin(), v.end(), num[i]) - v.begin();
			v[pos] = num[i];
		}
	}

	cout << N - v.size();
}