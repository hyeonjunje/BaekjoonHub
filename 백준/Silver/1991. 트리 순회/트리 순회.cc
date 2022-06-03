#include<iostream>
#include<unordered_map>

using namespace std;


pair<char, char> tree[26];

void myPreOrder(char root);
void myInOrder(char root);
void myPostOrder(char root);


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	char c1, c2, c3;
	for (int i = 0; i < N; i++)
	{
		cin >> c1 >> c2 >> c3;
		tree[c1 - 'A'] = {c2, c3};
	}

	myPreOrder('A');
	cout << '\n';
	myInOrder('A');
	cout << '\n';
	myPostOrder('A');
}

void myPreOrder(char root)
{
	if (root == '.') return;

	cout << root;
	myPreOrder(tree[root - 'A'].first);
	myPreOrder(tree[root - 'A'].second);
}
void myInOrder(char root)
{
	if (root == '.') return;

	myInOrder(tree[root - 'A'].first);
	cout << root;
	myInOrder(tree[root - 'A'].second);
}
void myPostOrder(char root)
{
	if (root == '.') return;

	myPostOrder(tree[root - 'A'].first);
	myPostOrder(tree[root - 'A'].second);
	cout << root;
}