#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define INF 500000000

struct edge {
	int n_v, dist;
	edge(int a, int b) : n_v(a), dist(b) {}
};

struct cmp {
	bool operator()(edge &a, edge &b) {
		return a.dist > b.dist;
	}
};

int N, E;
vector<edge> graph[805];
int d[805];
int dist_v1_v2;
bool v1_v2 = false;

int calc_v1_v2(int v1, int v2) {
	for (int i = 1; i <= N; i++) {
		d[i] = INF;
	}
	int ans = INF;

	priority_queue<edge, vector<edge>, cmp> pq;
	pq.push(edge(v1, 0));
	d[v1] = 0;

	while (!pq.empty()) {
		int c_v = pq.top().n_v;
		int c_dist = pq.top().dist;
		pq.pop();

		if (c_v == v2) {
			ans = min(ans, c_dist);
			continue;
			//return 여부 확인
		}

		for (int i = 0; i < graph[c_v].size(); i++) {
			int n_v = graph[c_v][i].n_v;
			int n_dist = graph[c_v][i].dist + c_dist;
			if (d[n_v] > n_dist) {
				d[n_v] = n_dist;
				pq.push(edge(n_v, n_dist));
			}
		}
	}

	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(edge(b, c));
		graph[b].push_back(edge(a, c));
	}

	int v1, v2;
	cin >> v1 >> v2;

	bool check_v1_v2 = false;
	dist_v1_v2 = calc_v1_v2(v1, v2);
	if (dist_v1_v2 == INF)
		check_v1_v2 = true;

	int ans = 0;
	int s_v1 = calc_v1_v2(1, v1);
	int v2_e = calc_v1_v2(v2, N);

	int s_v2 = calc_v1_v2(1, v2);
	int v1_e = calc_v1_v2(v1, N);

	if (s_v1 + v2_e > s_v2 + v1_e) {
		ans = s_v2 + v1_e;
	}
	else
		ans = s_v1 + v2_e;

	if (ans < INF && !check_v1_v2)
		cout << ans + dist_v1_v2 << '\n';
	else
		cout << -1 << '\n';



	return 0;
}
