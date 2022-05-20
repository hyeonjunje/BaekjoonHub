#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int seq[1000000]{};
int ans[1000000]{};

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	stack<int> s;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> seq[i];

	for (int i = N - 1; i >= 0; i--)
	{
		if (s.empty()) { ans[i] = -1; s.push(seq[i]); }


		else
		{
			while (seq[i] >= s.top())
			{
				s.pop();
				if (s.empty()) break;
			}
			if (s.empty()) ans[i] = -1;
			else ans[i] = s.top();

			s.push(seq[i]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << ' ';
	}

}