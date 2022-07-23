#include<iostream>
#include<vector>

#define MAX 500001
using namespace std;

int N;
int nums[MAX];
long long tree[MAX * 4];

vector<int> init(int start, int end, int node)
{
	if (start == end)
	{
		tree[node] = 0;
		vector<int> v = { nums[start] };
		return v;
	}

	int mid = (start + end) / 2;

	vector<int> leftV = init(start, mid, node * 2);
	vector<int> rightV = init(mid + 1, end, node * 2 + 1);

	vector<int> sortV;
	tree[node] = tree[node * 2] + tree[node * 2 + 1];

	int leftIdx = 0, rightIdx = 0;
	while (1)
	{
		if (leftIdx == leftV.size())
		{
			for (int i = rightIdx; i < rightV.size(); i++)
				sortV.push_back(rightV[i]);
			break;
		}
		else if (rightIdx == rightV.size())
		{
			for (int i = leftIdx; i < leftV.size(); i++)
				sortV.push_back(leftV[i]);
			break;
		}

		if (leftV[leftIdx] <= rightV[rightIdx])
		{
			sortV.push_back(leftV[leftIdx]);
			leftIdx++;
		}
		else
		{
			sortV.push_back(rightV[rightIdx]);
			rightIdx++;
			tree[node] += leftV.size() - leftIdx;
		}
	}
	return sortV;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> nums[i];
	}

	init(1, N, 1);

	//for (int i = 1; i <= N * 4; i++)
	//{
	//	cout << tree[i] << ' ';
	//}
	//cout << '\n';

	cout << tree[1];
}