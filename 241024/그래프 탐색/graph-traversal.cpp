#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visit[1001] = {false};
vector<int> graph[1001];
int result = 0;

void dfs(int current)
{
    visit[current] = true;

    for(int i = 0; i < graph[current].size(); ++i)
    {
        int next = graph[current][i];
        if(!visit[next])
        {
            dfs(next);
            result++;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);
    cout << result;
    return 0;
}