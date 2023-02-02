#include<iostream>
#include<vector>

using namespace std;



int main()
{
	int N, M, num;
	cin >> N >> M;

	vector<vector<int>> A;
	vector<vector<int>> B;

	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		for (int j = 0; j < M; j++)
		{
			cin >> num;
			temp.push_back(num);
		}
		A.push_back(temp);
	}

	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		for (int j = 0; j < M; j++)
		{
			cin >> num;
			temp.push_back(num);
		}
		B.push_back(temp);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << A[i][j] + B[i][j] << ' ';
		}
		cout << endl;
	}
}