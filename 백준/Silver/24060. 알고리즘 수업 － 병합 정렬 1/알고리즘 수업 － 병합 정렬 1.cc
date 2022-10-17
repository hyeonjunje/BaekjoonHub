#include<iostream>
#include<vector>

using namespace std;

vector<int> vec;
vector<int> tmp;

int myCount = 0;
int ans = -1;
int N, K;

void merge(int p, int q, int r)
{
	int i = p, j = q + 1, t = 0;

	while (i <= q && j <= r)
	{
		if (vec[i] <= vec[j])
		{
			tmp[t++] = vec[i++];
		}
		else
		{
			tmp[t++] = vec[j++];
		}
	}

	while (i <= q)
	{
		tmp[t++] = vec[i++];
	}
	while (j <= r)
	{
		tmp[t++] = vec[j++];
	}

	i = p, t = 0;
	while (i <= r)
	{
		myCount++;
		if (myCount == K)
		{
			ans = tmp[t];
		}
		vec[i++] = tmp[t++];
	}
}


void merge_sort(int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;

		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge(p, q, r);
	}
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		vec.push_back(num);
	}

	tmp.assign(vec.size(), 0);

	merge_sort(0, N - 1);


	cout << ans;
}