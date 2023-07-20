#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>

#define MAX_V 98765432100
#define MOD 100000009
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct info {
	int v, d;
	info(int vertex, int dist) : v(vertex), d(dist) {}
};

vector<info> graph[40001];
int parent[40001][17];
int depth[40001];
int dist[40001][17];

void make_tree(int curr) {
	for (int i = 0; i < graph[curr].size(); i++) {
		int next_v = graph[curr][i].v;
		int n_dist = graph[curr][i].d;
		if (depth[next_v] == -1) {
			depth[next_v] = depth[curr] + 1;
			dist[next_v][0] = n_dist;
			parent[next_v][0] = curr;
			make_tree(next_v);
		}
	}
}

int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		graph[u].push_back(info(v, d));
		graph[v].push_back(info(u, d));
	}

	memset(parent, -1, sizeof(parent));
	memset(depth, -1, sizeof(depth));

	depth[1] = 0;
	make_tree(1);

	for (int i = 1; i < 17; i++) {
		for (int j = 1; j <= N; j++) {
			if (parent[j][i - 1] != -1) {
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
				if (dist[j][i - 1] != 0)
					dist[j][i] = dist[j][i - 1] + dist[parent[j][i - 1]][i - 1];
			}
		}
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		int tu = u;
		int tv = v;
		if (depth[tu] < depth[tv]) {
			swap(tu, tv);
		}
		int diff = depth[tu] - depth[tv];
		int sum = 0;
		for (int j = 16; j >= 0; j--) {
			if (diff & (1 << j)) {
				sum += dist[tu][j];
				tu = parent[tu][j];
			}
		}

		if (tu != tv) {
			for (int j = 16; j >= 0; j--) {
				if (parent[tu][j] != -1 && parent[tu][j] != parent[tv][j]) {
					sum += (dist[tu][j] + dist[tv][j]);
					tu = parent[tu][j];
					tv = parent[tv][j];
				}
			}
			sum += (dist[tu][0] + dist[tv][0]);
		}

		cout << sum << '\n';

	}

	return 0;
}
