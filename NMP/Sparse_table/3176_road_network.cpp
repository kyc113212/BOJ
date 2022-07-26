#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>

#define MAX_V 987654321
#define MOD 100000007
#define T_MAX_V 1000000000
#define TREE_HEIGHT 20
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct info {
	int vertex, dist;
	info(int v, int d) : vertex(v), dist(d) {}
};

vector<info> graph[100001];
int parent[100001][TREE_HEIGHT];
int min_dist[100001][TREE_HEIGHT];
int max_dist[100001][TREE_HEIGHT];
int depth[100001];


void make_tree(int curr) {
	for (int i = 0; i < graph[curr].size(); i++) {
		int next_v = graph[curr][i].vertex;
		int next_d = graph[curr][i].dist;
		if (depth[next_v] == -1) {
			depth[next_v] = depth[curr] + 1;
			parent[next_v][0] = curr;
			max_dist[next_v][0] = min_dist[next_v][0] = next_d;
			make_tree(next_v);
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(parent, -1, sizeof(parent));
	memset(depth, -1, sizeof(depth));
	memset(min_dist, 1000001, sizeof(min_dist));
	memset(max_dist, 0, sizeof(max_dist));

	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		graph[u].push_back(info(v,d));
		graph[v].push_back(info(u,d));
	}

	depth[1] = 0;
	make_tree(1);

	for (int i = 1; i < TREE_HEIGHT; i++) {
		for (int j = 1; j <= N; j++) {
			if (parent[j][i - 1] != -1) {
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
				min_dist[j][i] = min(min_dist[parent[j][i - 1]][i - 1], min_dist[j][i - 1]);
				max_dist[j][i] = max(max_dist[parent[j][i - 1]][i - 1], max_dist[j][i - 1]);
			}
		}
	}

	int M;
	cin >> M;
	for (int k = 0; k < M; k++) {
		int u, v;
		cin >> u >> v;

		if (depth[u] < depth[v]) {
			swap(u, v);
		}
		int ans_min = 1000001;
		int ans_max = 0;
		int diff = depth[u] - depth[v];
		for (int i = TREE_HEIGHT - 1; i >= 0; i--) {
			if (diff & (1 << i)) {
				ans_max = max(ans_max, max_dist[u][i]);
				ans_min = min(ans_min, min_dist[u][i]);
				u = parent[u][i];
			}
		}

		if (u != v) {
			for (int i = TREE_HEIGHT - 1; i >= 0; i--) {
				if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
					ans_max = max(ans_max, max(max_dist[u][i], max_dist[v][i]));
					ans_min = min(ans_min, min(min_dist[u][i], min_dist[v][i]));
					u = parent[u][i];
					v = parent[v][i];
				}
			}
			ans_max = max(ans_max, max(max_dist[u][0], max_dist[v][0]));
			ans_min = min(ans_min, min(min_dist[u][0], min_dist[v][0]));
			u = parent[u][0];
		}
		cout << ans_min << ' ' << ans_max << ' ' << '\n';
	}
	

	return 0;
}
