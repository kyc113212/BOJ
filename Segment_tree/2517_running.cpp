#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct info {
	int idx, ability;
	info(int a, int b) : idx(a), ability(b) {}
};

bool cmp_idx(info &a, info &b){
	return a.idx < b.idx;
}
bool cmp_ability(info &a, info &b) {
	return a.ability > b.ability;
}

vector<int> tree;
vector<info> arr;
int N;

int query(int start, int end, int left, int right, int node) {
	if (start > right || end < left) {
		return 0;
	}
	if (start >= left && right >= end)
		return tree[node];
	int mid = (start + end) / 2;

	return query(start, mid, left, right, node * 2) + query(mid + 1, end, left, right, node * 2 + 1);
}

int update(int start, int end, int idx, int node) {
	if (start > idx || end < idx) {
		return tree[node];
	}
	if (start == end) {
		tree[node]++;
		return tree[node];
	}
	
	int mid = (start + end) / 2;
	return tree[node] = update(start, mid, idx, node * 2) + update(mid + 1, end, idx, node * 2 + 1);
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	arr.resize(N + 1, info(0,0));
	tree.resize(tree_size + 1);

	for (int i = 1; i <= N; i++) {
		cin >> arr[i].ability;
		arr[i].idx = i;
	}
	arr[0].idx = 0;
	arr[0].ability = 1000000005;

	sort(arr.begin(), arr.end(), cmp_ability);
	for (int i = 0; i <= N; i++) {
		arr[i].ability = i;
	}
	sort(arr.begin(), arr.end(), cmp_idx);

	for (int i = 1; i <= N; i++) {
		cout << query(1, N, 1, arr[i].ability, 1) + 1<< '\n';
		update(1, N, arr[i].ability, 1);
	}

	return 0;
}
