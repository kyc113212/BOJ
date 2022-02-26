#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N, M;

struct info {
	int dest, dist;
	info(int a, int b) : dest(a), dist(b) {}
};

struct cmp {
	bool operator()(info& a, info& b) {
		return a.dist > b.dist;
	}
};

vector<info> graph[200005];
bool visited[200005];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> N >> M;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			graph[i].clear();
		}
		if (N == 0 && M == 0)
			break;
		int sum = 0;
		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			graph[a].push_back(info(b, c));
			graph[b].push_back(info(a, c));
			sum += c;
		}


		priority_queue<info, vector<info>, cmp> pq;

		for (int i = 0; i < graph[0].size(); i++) {
			pq.push(info(graph[0][i].dest, graph[0][i].dist));
		}
		visited[0] = true;
		int ans = 0;

		while (!pq.empty()) {
			int cur_vertex = pq.top().dest;
			int cur_dist = pq.top().dist;
			pq.pop();

			if (visited[cur_vertex])
				continue;
			visited[cur_vertex] = true;

			ans += cur_dist;

			for (int i = 0; i < graph[cur_vertex].size(); i++) {
				int n_vertex = graph[cur_vertex][i].dest;
				if (visited[n_vertex])
					continue;
				else {
					pq.push(info(n_vertex, graph[cur_vertex][i].dist));
				}
			}
		}

		cout << sum - ans << '\n';
	}
	


	return 0;
}
