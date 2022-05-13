#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

struct pos {
	int y, x, cnt, wall_cnt;
	pos(int y, int x, int c, int wc) : y(y), x(x), cnt(c), wall_cnt(wc) {}
};

int map[1001][1001];
bool visited[1001][1001][11];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int N, M, K;

int bfs() {

	queue<pos> q;
	if (map[0][0] == 0) {
		q.push(pos(0, 0, 1, K));
	}
	else {
		if (K > 0) {
			q.push(pos(0, 0, 1, K-1));
		}
	}

	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		int c_wall = q.front().wall_cnt;
		int c_cnt = q.front().cnt;
		q.pop();
		//if (visited[cy][cx][c_wall])
		//	continue;
		//visited[cy][cx][c_wall] = true;
		if (cy == N - 1 && cx == M - 1) {
			return c_cnt;
		}
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int n_cnt = c_cnt + 1;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (visited[ny][nx][c_wall])
				continue;
			if (map[ny][nx]) {
				if (c_wall > 0) {
					if (n_cnt % 2 == 1) {
						//낮에만 벽 부수기 가능
						if (visited[ny][nx][c_wall - 1])
							continue;
						visited[cy][cx][c_wall] = 0;
						q.push(pos(cy, cx, n_cnt, c_wall));
					}
					else {
						if (visited[ny][nx][c_wall - 1])
							continue;
						visited[ny][nx][c_wall - 1] = true;
						q.push(pos(ny, nx, n_cnt, c_wall - 1));
					}
				}
				else
					continue;
			}
			else {
				visited[ny][nx][c_wall] = true;
				q.push(pos(ny, nx, n_cnt, c_wall));
			}
		}
	}


	return -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	cout << bfs() << '\n';

	return 0;
}
