#include<iostream>
#include<vector>

using namespace std;

int myInOrder[100001];
int myPostOrder[100001];

int idx[100001];

int N;

void preOrder(int inBegin, int inEnd, int postBegin, int postEnd)
{
	if (inBegin > inEnd || postBegin > postEnd) return;

	int root = myPostOrder[postEnd];
	cout << root << ' ';

	preOrder(inBegin, idx[root] - 1, postBegin, postBegin + (idx[root] - inBegin) - 1);
	preOrder(idx[root] + 1, inEnd, postBegin + (idx[root] - inBegin), postEnd - 1);
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> myInOrder[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> myPostOrder[i];
	}
	for (int i = 0; i < N; i++)
	{
		idx[myInOrder[i]] = i;
	}
	
	preOrder(0, N - 1, 0, N - 1);
}
