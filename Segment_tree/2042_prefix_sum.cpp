#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;
vector<ll> arr, tree;
int N, M, K;

ll init_tree(int start, int end, int node) {
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;

	return tree[node] = init_tree(start, mid, node * 2) + init_tree(mid + 1, end, node * 2 + 1);
}

void change_node(int start, int end, int node, int idx) {
	if (start > idx || end < idx)
		return;
	if (start == idx && end == idx) {
		tree[node] = arr[idx];
		return;
	}

	int mid = (start + end) / 2;
	change_node(start, mid, node * 2, idx);
	change_node(mid + 1, end, node * 2 + 1, idx);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll solve(int start, int end, int left, int right, int node) {
	if (start > right || end < left)
		return 0;
	if (start >= left && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return solve(start, mid, left, right, node * 2) + solve(mid + 1, end, left, right, node * 2 + 1);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	int tree_size = 1 << ((int)ceil(log2(N)) + 1);

	tree.resize(tree_size + 1);
	arr.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	init_tree(1, N, 1);

	for (int i = 0; i < M + K; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			int b;
			ll c;
			cin >> b >> c;
			arr[b] = c;
			change_node(1, N, 1, b);
			//change inx
		}
		else if (a == 2) {
			//calc sum
			int b, c;
			cin >> b >> c;
			cout << solve(1, N, b, c, 1) << '\n';
		}
	}


	return 0;
}
