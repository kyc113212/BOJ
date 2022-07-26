#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
vector<int> min_t, max_t;

void init_t(int start, int end, int node) {

	if (start == end) {
		min_t[node] = max_t[node] = v[start];
		return;
	}

	int mid = (start + end) / 2;
	init_t(start, mid, node * 2);
	init_t(mid + 1, end, node * 2 + 1);
	min_t[node] = min(min_t[node * 2], min_t[node * 2 + 1]);
	max_t[node] = max(max_t[node * 2], max_t[node * 2 + 1]);
	return;
}

int find_min(int node, int start, int end, int left, int right) {
	if (start > right || end < left)
		return 1000000001;

	if (start >= left && end <= right) {
		return min_t[node];
	}
	int mid = (start + end) / 2;

	return min(find_min(node * 2, start, mid, left, right), find_min(node * 2 + 1, mid + 1, end, left, right));

}

int find_max(int node, int start, int end, int left, int right) {
	if (start > right || end < left)
		return 0;

	if (start >= left && end <= right) {
		return max_t[node];
	}
	int mid = (start + end) / 2;

	return max(find_max(node * 2, start, mid, left, right), find_max(node * 2 + 1, mid + 1, end, left, right));

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	min_t.resize(tree_size,1000000001);
	max_t.resize(tree_size,0);

	init_t(0, N-1, 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		int minV = find_min(1, 1, N, a, b);
		int maxV = find_max(1, 1, N, a, b);

		cout << minV << " " << maxV << '\n';

	}

	return 0;
}
