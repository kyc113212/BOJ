#include <iostream>
#include <queue>

using namespace std;

struct info {
	int pos, cnt;
	info(int a, int b) : pos(a), cnt(b) {}
};

int visited[1001];
int arr[1001];
int N;

int bfs() {
	queue<info> q;
	q.push(info(0, 0));
	while (!q.empty()) {
		int c_pos = q.front().pos;
		int c_cnt = q.front().cnt;
		q.pop();

		if (c_pos == N - 1) {
			return c_cnt;
		}

		for (int i = 1; i <= arr[c_pos]; i++) {
			if (visited[c_pos + i])
				continue;
			visited[c_pos + i] = 1;
			q.push(info(c_pos + i, c_cnt + 1));
		}

	}

	return -1;
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cout << bfs() << '\n';

	return 0;
}
