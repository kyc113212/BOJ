#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> arr, tree;

int init_tree(int start, int end, int node) {
	if (start == end)
		return tree[node] = start;

	int mid = (start + end) / 2;
	int lo = init_tree(start, mid, node * 2);
	int hi = init_tree(mid + 1, end, node * 2 + 1);
	if (arr[lo] == arr[hi])
		return tree[node] = lo;
	else if (arr[lo] < arr[hi])
		return tree[node] = lo;
	else
		return tree[node] = hi;
}

int minIndex(int x, int y) // 두 인덱스를 받아 더 작은 값을 가지는 인덱스를 리턴
{
	if (arr[x] == arr[y]) return x < y ? x : y; // 같은 경우 더 작은 인덱스를 리턴
	return arr[x] < arr[y] ? x : y;
}

int change_num(int start, int end, int idx, int node) {
	if (start > idx || end < idx || start == end)
		return tree[node];

	int mid = (start + end) / 2;
	int lo = change_num(start, mid, idx, node * 2);
	int hi = change_num(mid + 1, end, idx, node * 2 + 1);

	if (arr[lo] == arr[hi])
		return tree[node] = lo;
	else if (arr[lo] < arr[hi])
		return tree[node] = lo;
	else
		return tree[node] = hi;
	//return tree[node] = minIndex(change_num(start, mid, idx,  node * 2), change_num(mid + 1, end, idx, node * 2 + 1));


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int h = (int)ceil(log2(N));
	int tree_size = 1 << (h + 1);

	arr.resize(N + 1);
	tree.resize(tree_size + 1);

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	init_tree(1, N, 1);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			int b, c;
			cin >> b >> c;
			arr[b] = c;
			change_num(1, N, b, 1);
		}
		else if(a == 2)
			cout << tree[1] << '\n';
	}

	return 0;
}
