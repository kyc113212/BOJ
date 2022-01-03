#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

struct info {
	ll next_v,dist;
	info(ll a, ll b) : next_v(a), dist(b) {}
};

struct cmp {
	bool operator() (info& a, info& b) {
		return a.dist > b.dist;
	}
};

int V, E;
vector<info> graph[100005];
int visited[100005];

bool check_all_visited() {
	for (int i = 1; i <= V; i++) {
		if (visited[i] == false)
			return false;
	}
	return true;
}

int main() {

	cin >> V >> E;
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 1; i <= E; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(info(b, c));
		graph[b].push_back(info(a, c));
	}

	visited[1] = 1;
	for (int i = 0; i < graph[1].size(); i++) {
		pq.push(info(graph[1][i].next_v, graph[1][i].dist));
	}

	ll ans = 0;
	while (!pq.empty()) {
		if (check_all_visited()) {
			break;
		}
		ll c_vertex = pq.top().next_v;
		ll c_dist = pq.top().dist;
		pq.pop();

		if (visited[c_vertex])
			continue;
		visited[c_vertex] = 1;
		ans += c_dist;
		
		for (int i = 0; i < graph[c_vertex].size(); i++) {
			ll n_vertex = graph[c_vertex][i].next_v;
			ll n_dist = graph[c_vertex][i].dist;
			if (visited[n_vertex])
				continue;
			pq.push(info(n_vertex, n_dist));
		}
	}

	cout << ans << '\n';

	return 0;
}
