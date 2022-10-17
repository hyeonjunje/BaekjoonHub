#include<iostream>
#include<string.h>

int ans;

int recursion(const char* s, int l, int r)
{
	ans++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s)
{
	return recursion(s, 0, strlen(s) - 1);
}

int main()
{
	int T;
	std::cin >> T;
	char s[1001];
	for (int i = 0; i < T; i++)
	{
		ans = 0;
		std::cin >> s;
		std::cout << isPalindrome(s);
		std::cout << " " << ans << '\n';
	}
}