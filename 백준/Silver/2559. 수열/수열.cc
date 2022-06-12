#include<iostream>
#include<algorithm>
using namespace std;

int num[100001]{};
int ans[100001]{};

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}

	for (int i = 1; i <= K; i++) ans[K] += num[i];

	for (int i = K + 1; i <= N; i++)
	{
		ans[i] = ans[i - 1] - num[i - K] + num[i];
	}

	cout << *max_element(ans + K, ans + N + 1);
}