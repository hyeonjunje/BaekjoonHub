#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> A;

int main()
{
	int N, M, temp, same = 0;
	cin >> N >>  M;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		A.push_back(temp);
	}
	sort(A.begin(), A.end());

	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		int index = lower_bound(A.begin(), A.end(), temp) - A.begin();

		if (index != A.size() && A[index] == temp) same++;
	}
	cout << N - same + M - same;
}