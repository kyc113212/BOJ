#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int N, M;
//int arr[100005];
vector<int> arr;
vector<int> tree;
//vector 사용 또는 tree array 사용 size비교

int init_tree(int start, int end, int node) {

	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;

	return tree[node] = init_tree(start, mid, node * 2) + init_tree(mid + 1, end, node * 2 + 1);
}

int sum_tree(int start, int end, int left, int right, int node) {
	if (start > right || end < left)
		return 0;
	if (start >= left && end <= right)
		return tree[node];
	int mid = (start + end) / 2;

	return sum_tree(start, mid, left, right, node * 2) + sum_tree(mid + 1, end, left, right, node * 2 + 1);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);
	arr.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	init_tree(0, N - 1, 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << sum_tree(1, N, a, b, 1) << '\n';
	}
	

	return 0;
}
