#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<int, bool> mySub(unordered_map<int, bool> A, unordered_map<int, bool> B)  // A - B
{
	unordered_map<int, bool> AsubB;
	for (auto elem : A)
	{
		if (B[elem.first] == false) AsubB[elem.first] = true;;
	}
	return AsubB;
}

unordered_map<int, bool> myAdd(unordered_map<int, bool> A, unordered_map<int, bool> B)
{
	unordered_map<int, bool> AaddB;
	for (auto elem : A)
		AaddB[elem.first] = elem.second;
	for (auto elem : B)
		AaddB[elem.first] = elem.second;

	return AaddB;
}

int main()
{
	int N, M, num;
	cin >> N >> M;

	unordered_map<int, bool> A;
	unordered_map<int, bool> B;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		A[num] = true;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		B[num] = true;
	}

	unordered_map<int, bool> AsubB = mySub(A, B);
	unordered_map<int, bool> BsubA = mySub(B, A);

	unordered_map<int, bool> ans = myAdd(AsubB, BsubA);

	cout << ans.size();
}