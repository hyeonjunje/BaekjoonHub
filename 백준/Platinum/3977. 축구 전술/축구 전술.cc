#include<iostream>
#include<vector>
#include<string.h>
#include<stack>
#include<algorithm>

using namespace std;
const int MAX = 100001;

int T, N, M, cnt, SN, check, sn[MAX], dfsn[MAX], indegree[MAX];
vector<int> adj[MAX];
bool finished[MAX];
bool visited[MAX];
stack<int> S;
vector<vector<int>> SCC;

int DFS(int curr) {
	dfsn[curr] = ++cnt;
	S.push(curr);

	int result = dfsn[curr];
	for (int next : adj[curr]) {
		if (dfsn[next] == 0) result = min(result, DFS(next));
		else if (!finished[next]) result = min(result, dfsn[next]);
	}

	if (result == dfsn[curr]) {
		vector<int> currSCC;
		while (1) {
			int t = S.top();
			S.pop();
			currSCC.push_back(t);
			finished[t] = true;
			sn[t] = SN;
			if (t == curr) break;
		}

		SCC.push_back(currSCC);
		SN++;
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N >> M;

		bool flag = false;
		check = -1;
		cnt = 0;
		SCC.clear();
		SN = 0;
		while (!S.empty()) S.pop();
		for (int i = 0; i < N; ++i)	adj[i].clear();
		memset(finished, false, sizeof(finished));
		memset(indegree, 0, sizeof(indegree));
		memset(dfsn, 0, sizeof(dfsn));
		memset(sn, -1, sizeof(sn));

		for (int i = 0; i < M; ++i) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}

		for (int i = 0; i < N; ++i)
			if (dfsn[i] == 0) DFS(i);

		for (int i = 0; i < N; ++i)
			for (int next : adj[i])
				if (sn[i] != sn[next]) indegree[sn[next]]++;


		for (int i = 0; i < SCC.size(); ++i) {
			if (indegree[i] == 0) {
				if (check == -1) check = i;
				else flag = true;
			}
		}

		if (flag) {
			cout << "Confused" << '\n';
		}
		else {
			sort(SCC[check].begin(), SCC[check].end());
			for (int i = 0; i < SCC[check].size(); ++i)
				cout << SCC[check][i] << '\n';

		}
		cout << '\n';

	}


	return 0;
}