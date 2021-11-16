#include <iostream>
#include <queue>

using namespace std;

struct info {
	int cur_stair, cnt;
	info(int a, int b) : cur_stair(a), cnt(b) {}
};

int visited[1000005];
int F, S, G, U, D;

int bfs() {
	
	if (G == S)
		return 0;

	visited[S] = 1;
	queue<info> q;
	q.push(info(S, 0));

	while (!q.empty()) {
		int cur_s = q.front().cur_stair;
		int cur_cnt = q.front().cnt;
		q.pop();

		int next1 = cur_s + U;
		if (next1 == G) {
			return cur_cnt + 1;
		}
		else {
			if (next1 <= F && visited[next1] == 0) {
				visited[next1] = 1;
				q.push(info(next1, cur_cnt + 1));
			}
		}

		int next2 = cur_s - D;
		if (next2 == G) {
			return cur_cnt + 1;
		}
		else {
			if (next2 > 0 && visited[next2] == 0) {
				visited[next2] = 1;
				q.push(info(next2, cur_cnt + 1));

			}
		}

	}

	return -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> F >> S >> G >> U >> D;

	int ans = bfs();

	if (ans == -1)
		cout << "use the stairs" << '\n';
	else
		cout << ans << '\n';

	return 0;
}
