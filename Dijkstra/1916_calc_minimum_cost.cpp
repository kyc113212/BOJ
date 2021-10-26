#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define INF 987654321

using namespace std;

struct item {
	int to, weight;
	item(int b, int c) : to(b), weight(c) {}
};

struct cmp {
	bool operator() (item &a, item &b) {
		return a.weight > b.weight;
	}
};

int dist[1001];
int N, M;
vector<pair<int,int>> graph[1001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}

	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	int start, end;
	cin >> start >> end;

	priority_queue<item, vector<item>, cmp> pq;
	dist[start] = 0;
	pq.push(item(start, 0));

	while (!pq.empty()) {
		int vertex = pq.top().to;
		int c_cost = pq.top().weight;
		pq.pop();

		if (c_cost > dist[vertex])
			continue;

		for (int i = 0; i < graph[vertex].size(); i++) {
			int n_vertex = graph[vertex][i].first;
			int n_cost = graph[vertex][i].second + c_cost;
			if (n_cost < dist[n_vertex]) {
				dist[n_vertex] = n_cost;
				pq.push(item(n_vertex, n_cost));
			}
		}
	}

	cout << dist[end] << '\n';

	return 0;
}
