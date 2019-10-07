#include <iostream>
#include <queue>

using namespace std;

int N;
int map[51][51];
int visited[51][51];
int minV = 9999;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct pos {
	int y, x, cnt;
	pos(int a, int b, int c) : y(a), x(b), cnt(c) {}
};

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	queue<pos> q;
	q.push(pos(0,0,0));
	visited[0][0] = 1;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int c_cnt = q.front().cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (visited[ny][nx] == 1)
				continue;
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (map[ny][nx] == 1) {
				q.push(pos(ny, nx, c_cnt));
				visited[ny][nx] = 1;
			}
			else if (map[ny][nx] == 0) {
				q.push(pos(ny, nx, c_cnt + 1));
				visited[ny][nx] = 
			}
		}
	}
//dist array를 만들어서 cnt 비교하여 거기다 계속 집어 넣는다.

	return 0;
}
