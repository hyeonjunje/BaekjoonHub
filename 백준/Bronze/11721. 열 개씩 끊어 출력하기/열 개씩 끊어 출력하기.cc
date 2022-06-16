#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	int count = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
		count++;
		if (count == 10) {
			cout << '\n'; count = 0;
		}
	}
}