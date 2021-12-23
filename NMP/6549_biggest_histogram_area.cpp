#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

vector<ll> arr;
vector<int> tree;
int N;

int init(int start, int end, int node) {
	if (start == end) {
		return tree[node] = start;
	}
	int mid = (start + end) / 2;
	int lo = init(start, mid, node * 2);
	int hi = init(mid + 1, end, node * 2 + 1);

	if (arr[lo] < arr[hi])
		return tree[node] = lo;
	else
		return tree[node] = hi;
}

int find_min_idx(int start, int end, int left, int right, int node) {
	if (start > right || end < left)
		return -1;
	if (start >= left && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	int lo = find_min_idx(start, mid, left, right, node * 2);
	int hi = find_min_idx(mid + 1, end, left, right, node * 2 + 1);

	if (lo == -1)
		return hi;
	else if (hi == -1)
		return lo;
	else {
		if (arr[lo] < arr[hi])
			return lo;
		else
			return hi;
	}
}

ll solve(int start, int end) {
	if (start > end)
		return -1;

	int idx = find_min_idx(0, N - 1, start, end, 1);
	ll ans = (end - start + 1) * arr[idx];

	if (start != idx) {
		ans = max(ans, solve(start, idx - 1));
	}
	if (end != idx) {
		ans = max(ans, solve(idx + 1, end));
	}

	return ans;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> N;
		if (N == 0)
			break;
		arr.clear();
		tree.clear();
		int h = (int)ceil(log2(N));
		int tree_size = (1 << (h + 1));
		arr.resize(N);
		tree.resize(tree_size);
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		init(0, N - 1, 1);
		cout << solve(0, N - 1) << '\n';
	}
	

	return 0;
}
