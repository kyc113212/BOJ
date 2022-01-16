#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct info {
	int n_v, w_t;
	info(int a, int b) : n_v(a), w_t(b) {}
};

int N, K, W;
int start_time[1005];
int now[1005];

int solve(vector<int> graph[], vector<int> & work_time) {
	
	queue<info> q;
	for (int i = 1; i <= N; i++) {
		if (now[i] == 0)
			q.push(info(i, 0));
	}

	int ans = 0;

	while (!q.empty()) {
		int vertex = q.front().n_v;
		int s_time = q.front().w_t;
		int f_time = s_time + work_time[vertex];
		q.pop();

		if (vertex == W) {
			return f_time;
		}

		if (f_time > ans) {
			ans = f_time;
		}

		for (int i = 0; i < graph[vertex].size(); i++) {
			int n_v = graph[vertex][i];
			start_time[n_v] = max(start_time[n_v], f_time);
			now[n_v]--;
			if (now[n_v] == 0) {
				q.push(info(n_v, start_time[n_v]));
			}
		}

	}

	return 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		vector<int> work_time;
		vector<int> graph[1005];
		memset(now, 0, sizeof(now));
		memset(start_time, 0, sizeof(start_time));
		cin >> N >> K;

		work_time.push_back(0);
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			work_time.push_back(a);
		}
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			now[b]++;
		}
		cin >> W;
		cout << solve(graph, work_time) << '\n';

	}

	return 0;
}
