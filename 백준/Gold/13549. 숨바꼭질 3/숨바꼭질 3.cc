#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int d[200001]{};
int N, K;


void dijkstra(int start)
{
	deque<int> dq;
	dq.push_back(start);
	d[start] = 0;

	while (!dq.empty())
	{
		int current = dq.front();
		dq.pop_front();

		if (current == K) return;

		int warp = current * 2;
		if (warp <= 200000 && d[warp] > d[current])
		{
			d[warp] = d[current];
			dq.push_front(warp);
		}

		int l = current - 1, r = current + 1;
		if (l >= 0 && d[l] > d[current] + 1)
		{
			d[l] = d[current] + 1;
			dq.push_back(l);
		}
		if (r <= 200000 && d[r] > d[current] + 1)
		{
			d[r] = d[current] + 1;
			dq.push_back(r);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	fill(d, d + 200001, 1e9);
	dijkstra(N);

	cout << d[K];
}