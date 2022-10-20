#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s, ex, temp = "";
	cin >> s >> ex;

	stack<char> s1;
	stack<char> s2;

	int t = 0;
	bool isSame = false;
	for (int i = 0; i < s.length(); i++)
	{
		s1.push(s[i]);

		if (i >= ex.size() - 1)
		{
			if (s[i] == ex[ex.size() - 1])
			{
				isSame = true;
				for (int j = ex.size() - 1; j >= 0; j--)
				{
					if (s1.top() != ex[j])
					{
						isSame = false;
						break;
					}

					s2.push(s1.top());
					s1.pop();
				}

				if (isSame)
				{
					while (!s2.empty())
					{
						s2.pop();
					}
				}
				else
				{
					while (!s2.empty())
					{
						s1.push(s2.top());
						s2.pop();
					}
				}
			}
		}
	}

	string ans = "";
	while (!s1.empty())
	{
		ans += s1.top();
		s1.pop();
	}
	reverse(ans.begin(), ans.end());

	if (ans.size() == 0)
		cout << "FRULA";
	else
		cout << ans;
}