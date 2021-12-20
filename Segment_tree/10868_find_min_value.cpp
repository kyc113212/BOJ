#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> arr, tree;
int N, M;

int init_tree(int start, int end, int node) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;

	return tree[node] = min(init_tree(start, mid, node * 2), init_tree(mid + 1, end, node * 2 + 1));
}

int find_minV(int start, int end, int left, int right, int node) {
	if (start > right || end < left) {
		return 1000000005;
	}
	if (start >= left && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return min(find_minV(start, mid, left, right, node * 2), find_minV(mid + 1, end, left, right, node * 2 + 1));
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> N >> M;
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));

	arr.resize(N);
	tree.resize(tree_size,1000000005);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	init_tree(0, N - 1, 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << find_minV(1, N, a, b, 1) << '\n';
	}

	return 0;
}
