#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	int num[100001];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	sort(num, num + N);

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans = max(ans, num[i] * (N - i));
	}
	cout << ans;
}