#include<iostream>

using namespace std;

bool A[101][101];

int main()
{
	int N, x, y, result = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		for (int j = 0; j < 10; j++)
			for (int h = 0; h < 10; h++)
				A[y + j][x + h] = true;
	}

	for (int i = 1; i < 101; i++)
		for (int j = 1; j < 101; j++)
			if (A[i][j])
				result++;

	cout << result;
}