#include<iostream>
#include<vector>

using namespace std;

//#define MAX 10000

int tree[10000];

void makeTree(int start, int end)
{
	if (start >= end) return;

	if (start == end - 1)
	{
		cout << tree[start] << '\n';
		return;
	}

	int idx = 0;

	for (idx = start + 1; idx < end; idx++)
	{
		if (tree[start] < tree[idx]) break;
	}

	makeTree(start + 1, idx);
	makeTree(idx, end);
	cout << tree[start] << '\n';
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, size = 0;

	while (cin >> a)
	{
		if (a == cin.fail()) break;
		tree[size++] = a;
	}

	makeTree(0, size);

	return 0;
}
