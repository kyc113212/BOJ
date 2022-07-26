#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct edge {
	int st, ed, dst;
	edge(int a, int b, int c) : st(a), ed(b), dst(c) {}
};

struct cmp {
	bool operator()(edge& a, edge& b) {
		return a.dst > b.dst;
	}
};

int N, M;
int parent[100005];

int find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}

bool isUnion(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return true;
	return false;
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y)
		return;
	parent[y] = x;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> rst;
	priority_queue<edge, vector<edge>, cmp> pq;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push(edge(a, b, c));
	}

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	while (!pq.empty()) {
		if (!isUnion(pq.top().st, pq.top().ed)) {
			merge(pq.top().st, pq.top().ed);
			rst.push_back(pq.top().dst);
		}
		pq.pop();
	}

	int ans = 0;
	for (int i = 0; i < rst.size() - 1; i++) {
		ans += rst[i];
	}
	cout << ans << '\n';

	return 0;
}
