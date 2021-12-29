#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int N,M,K;
vector<ll> arr, tree;

ll init_tree(int start, int end, int node) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = (init_tree(start, mid, node * 2) * init_tree(mid + 1, end, node * 2 + 1)) % 1000000007;
}

ll update_tree(int start, int end, int idx, int node) {
	if (start > idx || end < idx)
		return tree[node];
	if (idx == start && idx == end) {
		return tree[node] = arr[idx];
	}
	int mid = (start + end) / 2;
	return tree[node] = (update_tree(start, mid, idx, node * 2) * update_tree(mid + 1, end, idx, node * 2 + 1)) % 1000000007;
}

ll solve(int start, int end, int left, int right, int node) {
	if (start > right || end < left)
		return 1;
	if (left <= start && right >= end) {
		return tree[node];
	}

	int mid = (start + end) / 2;
	return (solve(start, mid, left, right, node * 2) * solve(mid + 1, end, left, right, node * 2 + 1)) % 1000000007;
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

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	init_tree(1, N, 1);
	
	for (int i = 0; i < M + K; i++) {
		int a;
		cin >> a;
		if (a == 1) {//b번째 수를 c로 변경
			int idx;
			ll val;
			cin >> idx >> val;
			arr[idx] = val;
			update_tree(1, N, idx, 1);
		}
		else if (a == 2) { // b부터 c의 곱을 출력
			int b, c;
			cin >> b >> c;
			cout << solve(1, N, b, c, 1) << '\n';
		}
	}


	return 0;
}
