#include<iostream>
#include<math.h>
using namespace std;

int N, r, c;
int ans = 0;
void z(int size, int rStart, int rEnd, int cStart, int cEnd)
{
	if (size == 0) return;

	int rMid = (rStart + rEnd) / 2;
	int cMid = (cStart + cEnd) / 2;

	if (r <= rMid && c <= cMid) { z(size / 4, rStart, rMid, cStart, cMid); ans += (size / 4) * 0; } // 2사분면
	if (r <= rMid && c > cMid) { z(size / 4, rStart, rMid, cMid + 1, cEnd); ans += (size / 4) * 1; } // 1사분면
	if (r > rMid && c <= cMid) { z(size / 4, rMid + 1, rEnd, cStart, cMid); ans += (size / 4) * 2; } // 3사분면
	if (r > rMid && c > cMid) { z(size / 4, rMid + 1, rEnd, cMid + 1, cEnd); ans += (size / 4) * 3; } // 4사분면
}

int main()
{
	cin >> N >> r >> c;
	int size = pow(2, N) * pow(2, N);
	
	z(size, 0, pow(2, N) - 1, 0, pow(2, N) - 1);
	cout << ans;
}