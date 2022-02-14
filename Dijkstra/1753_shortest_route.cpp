#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define INF 987654321

struct info {
	int to, dist;
	info(int a, int b) : to(a), dist(b) {}
};

struct cmp {
	bool operator()(info& a, info& b) {
		return a.dist > b.dist;
	}
};

int V, E;
int startV;
vector<info> graph[20005];
int d[20005];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> startV;
	for (int i = 1; i <= V; i++) {
		d[i] = INF;
	}

	d[startV] = 0;
	priority_queue<info, vector<info>, cmp> pq;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(info(b, c));
		if (a == startV) {
			pq.push(info(b, c));
		}
	}
	
	while (!pq.empty()) {
		
		int c_dist = pq.top().dist;
		int c_v = pq.top().to;
		pq.pop();

		if (c_dist > d[c_v])
			continue;
		d[c_v] = c_dist;
		for (int i = 0; i < graph[c_v].size(); i++) {
			int n_v = graph[c_v][i].to;
			int n_dist = graph[c_v][i].dist;
			if (d[n_v] > n_dist + c_dist) {
				d[n_v] = n_dist + c_dist;
				pq.push(info(n_v, n_dist + c_dist));
			}
		}

	}

	for (int i = 1; i <= V; i++) {
		if (d[i] == INF)
			cout << "INF" << '\n';
		else
			cout << d[i] << '\n';
	}

	return 0;
}
