#include<iostream>


using namespace std;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	cout << (N % 2 == 0 ? "SK" : "CY");
}