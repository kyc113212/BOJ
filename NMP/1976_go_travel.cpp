#include <iostream>

using namespace std;

int N, M;
int parent[205];

int find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}

bool isUnion(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y)
		return false;
	return true;
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	parent[y] = x;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				if (!isUnion(i, j)) {
					merge(i, j);
				}
			}
		}
	}


	bool check = false;
	int a;
	cin >> a;
	int b = find(a);
	for (int i = 1; i < M; i++) {
		int c;
		cin >> c;
		if (find(c) != b) {
			check = true;
			break;
		}
	}

	if (check)
		cout << "NO" << '\n';
	else
		cout << "YES" << '\n';

	return 0;
}
