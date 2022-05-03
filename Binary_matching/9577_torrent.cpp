#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_V 101

vector<int> t[MAX_V];
int op[MAX_V];
bool done[MAX_V];
int N, M;

bool all_visited() {
	for (int i = 1; i <= N; i++) {
		if (op[i] == -1)
			return false;
	}
	return true;
}

bool dfs(int v) {
	for (int i = 0; i < t[v].size(); i++) {
		int p = t[v][i];
		if (done[p])
			continue;
		done[p] = true;
		if (op[p] == -1 || dfs(op[p])) {
			op[p] = v;
			return true;
		}
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cin >> N >> M;
		int end_t = 0;
		int ans = -1;
		memset(op, -1, sizeof(op));
		for (int i = 0; i <= 100; i++) {
			t[i].clear();
		}
		for (int i = 0; i < M; i++) {
			int t1, t2, a;
			cin >> t1 >> t2 >> a;
			end_t = max(end_t, t2);
			for (int j = 0; j < a; j++) {
				int q;
				cin >> q;
				for (int k = t1; k < t2; k++) {
					t[k].push_back(q);
				}
			}
		}

		for (int i = 0; i <= end_t; i++) {
			memset(done, false, sizeof(done));
			dfs(i);
			if (all_visited()) {
				ans = i + 1;
				break;
			}
		}

		cout << ans << '\n';


	}

	return 0;
}
