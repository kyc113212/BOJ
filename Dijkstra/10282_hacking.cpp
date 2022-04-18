#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct info {
	int next_v, sp_time, st_time;
	info(int nv, int spt, int stt) : next_v(nv), sp_time(spt), st_time(stt) {}
};

struct cmp {
	bool operator()(info& a, info& b) {
		if (a.st_time == b.st_time) {
			return a.sp_time > b.sp_time;
		}
		return a.st_time > b.st_time;
	}
};

#define MAX_V 987654321

int dist[10001];
vector<info> graph[10001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int N, D, C;
		cin >> N >> D >> C;
		int ans = 0;
		int cnt = 0;
		fill(dist, dist + N + 1, MAX_V);
		for (int i = 0; i <= N; i++) {
			graph[i].clear();
		}
		priority_queue<info, vector<info>, cmp> pq;
		for (int i = 0; i < D; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			graph[b].push_back(info(a, s, 0));
		}

		for (int i = 0; i < graph[C].size(); i++) {
			pq.push(info(graph[C][i].next_v, graph[C][i].sp_time, 0));
		}
		dist[C] = 0;
		while (!pq.empty()) {
			int c_v = pq.top().next_v;
			int sp_time = pq.top().sp_time;
			int st_time = pq.top().st_time;
			pq.pop();
			if (dist[c_v] <= sp_time + st_time) {
				continue;
			}
			dist[c_v] = sp_time + st_time;
			for (int i = 0; i < graph[c_v].size(); i++) {
				int n_v = graph[c_v][i].next_v;
				int n_t = graph[c_v][i].sp_time;
				pq.push(info(n_v, n_t, st_time + sp_time));
			}
		}

		for (int i = 1; i <= N; i++) {
			if (dist[i] != MAX_V) {
				ans = max(ans, dist[i]);
				cnt++;
			}		
		}

		cout << cnt << " " << ans << "\n";

	}

	return 0;
}
