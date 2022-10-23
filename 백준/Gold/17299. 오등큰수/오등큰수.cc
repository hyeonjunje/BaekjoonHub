#include<iostream>
#include<stack>

#define MAX 1000001
using namespace std;

int A[MAX];
int F[MAX];
int NGF[MAX];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	stack<int> s;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		F[A[i]]++;
	}

	for (int i = N - 1; i >= 0; i--)
	{
		if (s.empty())
		{
			s.push(A[i]);
			NGF[i] = -1;
		}
		else
		{
			while (!s.empty())
			{
				if (F[s.top()] > F[A[i]])
					break;

				s.pop();
			}

			if (!s.empty())
				NGF[i] = s.top();
			else
				NGF[i] = -1;
			s.push(A[i]);
		}
	}

	for (int i = 0; i < N; i++)
		cout << NGF[i] << ' ';
}
