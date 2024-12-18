#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000

int BinarySearch(const vector<int>& v, int target)
{
    int left = 0;
    int right = v.size() - 1;
    while(left < right)
    {
        int mid = left + (right - left) / 2;

        if(v[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return left;
}

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    cin >> n;
    int arr[MAX] = {0};
    for(int i = n - 1; i >= 0; --i)
    {
        cin >> arr[i];
    }
    
    vector<int> v;
    v.push_back(arr[0]);

    for(int i = 0; i < n; ++i)
    {
        if(v[v.size() - 1] < arr[i])
        {
            v.push_back(arr[i]);
        }
        else
        {
            int index = BinarySearch(v, arr[i]);
            v[index] = arr[i];
        }
    }

    cout << v.size();
    return 0;
}