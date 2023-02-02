#include<iostream>
#include<vector>

using namespace std;

int A[9][9];

int main()
{
	int result = -1;
	int row, col;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> A[i][j];
			if (result < A[i][j])
			{
				result = A[i][j];
				row = i + 1;
				col = j + 1;
			}
		}
	}

	cout << result << endl << row << ' ' << col;

}