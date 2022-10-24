#include<iostream>
#include<stack>

#define MAX 100010
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	long long ans = 0;
	long long* h = new long long[MAX] {};
	
	stack<int> s;

	for (int i = 1; i < N + 1; i++)
	{
		cin >> h[i];
	}

	s.push(0);

	for (int i = 1; i < N + 2; i++)
	{
		if (h[i] < h[s.top()])
		{
			while (h[i] < h[s.top()])
			{
				long long check = h[s.top()];
				s.pop();

				ans = max(ans, check * (i - s.top() - 1));
			}
		}
		s.push(i);
	}

	cout << ans;
}