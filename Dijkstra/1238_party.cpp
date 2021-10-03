#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321

using namespace std;

struct info {
	int to, cost;
	info(int a, int b) : to(a), cost(b) {}
};

struct cmp {
	bool operator() (info &a, info &b) {
		return a.cost > b.cost;
	}
};

int N, M, X;
vector<info> graph[1001];
vector<int> dist;
int rst_dist[1002];

void dij(int v) {

	dist.clear();
	dist.resize(N + 1, INF);

	priority_queue<info, vector<info>, cmp> pq;

	dist[v] = 0;
	pq.push(info(v, 0));

	while (!pq.empty()) {
		int c_vertex = pq.top().to;
		int c_cost = pq.top().cost;
		pq.pop();

		if (dist[c_vertex] < c_cost)
			continue;

		for (int i = 0; i < graph[c_vertex].size(); i++) {
			int n_cost = c_cost + graph[c_vertex][i].cost;
			int n_vertex = graph[c_vertex][i].to;

			if (dist[n_vertex] > n_cost) {
				dist[n_vertex] = n_cost;
				pq.push(info(n_vertex, n_cost));
			}
		}
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(info(b, c));
	}

	for (int i = 1; i <= N; i++) {
		dij(i);
		rst_dist[i] = dist[X];
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		dij(X);
		rst_dist[i] += dist[i];
		ans = max(ans, rst_dist[i]);
	}

	cout << ans << endl;

	return 0;
}
