#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
   int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a; 
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int solution(int n) {
    int answer = 0;
    
    int a = lcm(n, 6);
    
    answer = a / 6;
    
    return answer;
}