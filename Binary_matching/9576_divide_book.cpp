#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define MAX_V 1001

using namespace std;

int N, M;
vector<int> graph[MAX_V];
int op[MAX_V];
int done[MAX_V];

bool dfs(int v) {
	for (int i = 0; i < graph[v].size(); i++) {
		int p = graph[v][i];
		if (done[p])
			continue;
		done[p] = true;
		if (op[p] == 0 || dfs(op[p])) {
			op[p] = v;
			return true;
		}
	}

	return false;
}

int main() {

	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int N, M;
		cin >> N >> M;
		memset(op, 0, sizeof(op));
		for (int i = 1; i <= M; i++) {
			graph[i].clear();
		}
		for (int i = 1; i <= M; i++) {
			int a, b;
			cin >> a >> b;
			for (int j = a; j <= b; j++) {
				graph[i].push_back(j);
			}
		}

		int cnt = 0;
		for (int i = 1; i <= M; i++) {
			memset(done, 0, sizeof(done));
			if (dfs(i)) {
				cnt++;
			}
		}

		cout << cnt << '\n';

	}

	return 0;
}
