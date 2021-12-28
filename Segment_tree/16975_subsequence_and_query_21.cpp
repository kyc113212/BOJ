#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

int N, M;
vector<ll> arr, tree, lazy;

ll init_tree(int start, int end, int node) {
	if (start == end) {
		return tree[node] = arr[start];
	}	
	int mid = (start + end) / 2;
	return tree[node] = init_tree(start, mid, node * 2) + init_tree(mid + 1, end, node * 2 + 1);
}

void update_lazy(int start, int end, int node) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	return;
}

void update_range(int start, int end, int left, int right, int node, int val) {
	update_lazy(start, end, node);

	if (start > right || end < left)
		return;
	if (start >= left && end <= right) {
		tree[node] += (end - start + 1) * val;
		if (start != end) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}

	int mid = (start + end) / 2;
	update_range(start, mid, left, right, node * 2, val);
	update_range(mid + 1, end, left, right, node * 2 + 1, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];

	return;
}

ll find_num(int start, int end, int node, int idx) {
	update_lazy(start, end, node);

	if (start > idx || end < idx)
		return 0;
	if (start >= idx && end <= idx) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return find_num(start, mid, node * 2, idx) + find_num(mid + 1, end, node * 2 + 1, idx);
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size + 1);
	lazy.resize(tree_size + 1);
	arr.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	init_tree(1, N, 1);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			int b, c, d;
			cin >> b >> c >> d;
			update_range(1, N, b, c, 1, d);
		}
		else if (a == 2) {
			int b;
			cin >> b;
			cout << find_num(1, N, 1, b) << '\n';
		}
	}

	return 0;
}
