#include <iostream>

#include <algorithm>

#include <vector>

#include <cmath>

 

using namespace std;

 

int N, M;

vector<int> tree;

 

int update(int start, int end, int idx, int val, int node) {

	if (start > idx || end < idx) {

		return tree[node];

	}

	if (start == end) {

		return tree[node] = val;

	}

	int mid = (start + end) / 2;

	return tree[node] = update(start, mid, idx, val, node * 2) + update(mid + 1, end, idx, val, node * 2 + 1);

}

 

int sum_num(int start, int end, int left, int right, int node) {

	if (start > right || end < left) {

		return 0;

	}

	if (start >= left && end <= right)

		return tree[node];

	int mid = (start + end) / 2;

	return sum_num(start, mid, left, right, node * 2) + sum_num(mid + 1, end, left, right, node * 2 + 1);

}

 

int main() {

 

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);

 

	cin >> N >> M;

	int h = (int)ceil(log2(N));

	int tree_size = (1 << (h + 1));

	tree.resize(tree_size);

 

	for (int i = 0; i < M; i++) {

		int a;

		cin >> a;

		if (a == 0) {

			//sum number

			int b, c;

			cin >> b >> c;

			if (b > c) {

				swap(b, c);

			}

			cout << sum_num(1, N, b, c, 1) << '\n';

		}

		else {

			//modify number

			int b, c;

			cin >> b >> c;

			//arr[b]에 c를 삽입한다.

			update(1, N, b, c, 1);

		}

	}

 

	return 0;

}
