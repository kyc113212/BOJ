#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr, tree;

int init(int start, int end, int node) {
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int solve(int start, int end, int left, int right, int node) {
	
	if (start > right || end < left) {
		return 1000000005;
	}
	if (start >= left && end <= right)
		return tree[node];
	int mid = (start + end) / 2;

	return min(solve(start, mid, left, right, node * 2), solve(mid + 1, end, left, right, node * 2 + 1));
}

int update(int start, int end, int index, int change_num, int node) {
	if (index < start || end < index) {
		return tree[node];
	}
	if (start == end)
		return tree[node] = arr[index];
	int mid = (start + end) / 2;

	return tree[node] = min(update(start, mid, index, change_num, node * 2), update(mid + 1, end, index, change_num, node * 2 + 1));
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	arr.resize(N+ 1);
	tree.resize(tree_size);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	init(1, N, 1);

	cin >> M;
	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			arr[b] = c;
			update(1, N, b, c, 1);
		}
		else {
			cout << solve(1, N, b, c, 1) << '\n';
		}
	}

	return 0;
}
