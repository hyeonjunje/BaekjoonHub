#include<iostream>
#define MAX 1001
using namespace std;

int cost[MAX];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i];
	}
	cost[0] = 10001;
	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j > 0; j--)
		{
			cost[i] = min(cost[i], cost[i - j] + cost[j]);
		}
	}
	//for (int i = 1; i <= N; i++)
	//{
	//	cout << cost[i] << ' ';
	//}
	cout << cost[N];
}