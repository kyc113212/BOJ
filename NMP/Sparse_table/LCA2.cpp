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

vector<int> graph[100001];
int depth[100001];
int parent[100001][18];

void make_tree(int curr) {

	for (int next : graph[curr]) {
		if (depth[next] == -1) {
			parent[next][0] = curr;
			depth[next] = depth[curr] + 1;
			make_tree(next);
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	memset(depth, -1, sizeof(depth));
	memset(parent, -1, sizeof(parent));

	depth[1] = 0;
	make_tree(1);

	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= N; j++) {
			if(parent[j][i - 1] != -1)
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		if (depth[u] < depth[v]) {
			swap(u, v);
		}
		int diff = depth[u] - depth[v];

		for (int j = 0; diff; j++) {
			if (diff % 2) {
				u = parent[u][j];
			}
			diff /= 2;
		}

		if (u != v) {
			for (int j = 17; j >= 0; j--) {
				if (depth[u] != -1 && parent[u][j] != parent[v][j]) {
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			u = parent[u][0];
		}
		
		cout << u << '\n';
	}

	return 0;
}
