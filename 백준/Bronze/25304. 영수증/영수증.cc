#include<iostream>


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int X, N, a, b, ans = 0;
	std::cin >> X;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> a >> b;
		ans += a * b;
	}
	std::cout << (ans == X ? "Yes" : "No");
}
