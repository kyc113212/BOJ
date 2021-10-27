#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define INF 987654321

using namespace std;

struct item {
	int from, to, weight;
	item(int a, int b, int c) : from(a), to(b), weight(c) {}
};

struct cmp {
	bool operator() (item &a, item &b) {
		if (a.weight == b.weight)
			return a.to > b.to;
		else
			return a.weight > b.weight;
	}
};

int dist[1001];
int N, M;
vector<pair<int,int>> graph[1001];
vector<int> dept[1001];

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
	pq.push(item(start,start, 0));
	//route.push_back(start);
	dept[start].push_back(start);

	while (!pq.empty()) {
		int start_V = pq.top().from;
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
				pq.push(item(vertex, n_vertex, n_cost));
				dept[n_vertex].clear();
				for (int j = 0; j < dept[vertex].size(); j++) {
					dept[n_vertex].push_back(dept[vertex][j]);
				}
				dept[n_vertex].push_back(n_vertex);
			}
		}
	}

	cout << dist[end] << '\n';
	cout << dept[end].size() << '\n';
	for (int i = 0; i < dept[end].size(); i++) {
		cout << dept[end][i] << " ";
	}
	cout << '\n';

	return 0;
}
