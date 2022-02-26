#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct pos {
	int y, x;
	pos(int a, int b) : y(a), x(b) {}
};

struct info {
	int st,ed;
	double dist;
	info(int a, int b, double c) : st(a), ed(b), dist(c) {}
};

struct cmp {
	bool operator()(info& a, info& b) {
		return a.dist > b.dist;
	}
};

int N, M;
int parent[1005];
vector<pos> v;
//find,merge,isunion


int find(int v) {
	if (parent[v] == v) {
		return v;
	}
	return parent[v] = find(parent[v]);
}

void merge(int y, int x) {
	y = find(y);
	x = find(x);

	if (y == x)
		return;

	parent[y] = x;
}

bool isUnion(int y, int x) {
	y = find(y);
	x = find(x);
	
	if (y == x)
		return true;
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed;
	cout.precision(2);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N; i++) {
		int y, x;
		cin >> y >> x;
		v.push_back(pos(y, x));	
	}


	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (!isUnion(a, b)) {
			merge(a, b);
		}
	}	

	double ans = 0;
	priority_queue<info, vector<info>, cmp> pq;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			double dist = sqrt(pow((v[i].y - v[j].y), 2) + pow((v[i].x - v[j].x), 2));
			pq.push(info(i + 1, j + 1, dist));
		}
	}

	while (!pq.empty()) {
		if (!isUnion(pq.top().st, pq.top().ed)) {
			merge(pq.top().st, pq.top().ed);
			ans += pq.top().dist;
		}
		pq.pop();
	}

	cout << ans << '\n';

	return 0;
}
