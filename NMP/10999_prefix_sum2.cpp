#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
int N, M, K;
vector<ll> tree, lazy, arr;

ll create_tree(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = create_tree(node * 2, start, mid) + create_tree(node * 2 + 1, mid + 1, end);
}

void update_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += ((ll)end - start + 1) * lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	return;
}

void update_range(int node ,int start, int end, int left, int right, ll val) {
	update_lazy(node, start, end);

	if (start > right || end < left)
		return;
	if (start >= left && end <= right) {
		//범위 내에 완전히 포함
		tree[node] += ((ll)end - start + 1) * val;
		if (start != end) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}

	int mid = (start + end) / 2;
	update_range(node * 2, start, mid, left, right, val);
	update_range(node * 2 + 1, mid + 1, end, left, right, val);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (start > right || end < left)
		return 0;
	if (start >= left && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return query(node * 2, 
		start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	arr.resize(N + 1);
	tree.resize(tree_size + 1);
	lazy.resize(tree_size + 1);

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	create_tree(1, 1, N);

	for (int i = 0; i < M + K; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			//b에서 c까지 d를 더한다
			int b, c;
			ll d;
			cin >> b >> c >> d;
			//update range
			update_range(1, 1, N, b, c, d);
		}
		else if (a == 2) {
			//b부터 c까지의 합을 더한다
			int b, c;
			cin >> b >> c;
			cout << query(1, 1, N, b, c) << '\n';
		}
	}

	return 0;
}
