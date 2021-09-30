#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N;
int map[51][51];
int visited[51][51];
int dist[51][51];
int minV = 9999;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans = 0;

struct pos {
	int y, x, cnt;
	pos(int a, int b, int c) : y(a), x(b), cnt(c) {}
};

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = 999999;
		}
	}

	queue<pos> q;
	visited[0][0] = 1;
	if (map[0][0] == 1) {
		q.push(pos(0, 0, 0));
		dist[0][0] = 0;
	}
	else if (map[0][0] == 0) {
		q.push(pos(0, 0, 1));
		dist[0][0] = 1;
	}
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int c_cnt = q.front().cnt;
		/*if (cx == N - 1 && cy == N - 1) {
			minV = min(minV, c_cnt);
		}*/
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			//if (visited[ny][nx] == 1)
			//	continue;
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (map[ny][nx] == 1) {
				if (dist[ny][nx] > c_cnt) {
					q.push(pos(ny, nx, c_cnt));
					dist[ny][nx] = c_cnt;
					visited[ny][nx] = 1;
				}
			}
			else if (map[ny][nx] == 0) {
				if (dist[ny][nx] > c_cnt + 1) {
					q.push(pos(ny, nx, c_cnt + 1));
					dist[ny][nx] = c_cnt + 1;
					visited[ny][nx] = 1;
				}
			}
		}
	}
	//dist array를 만들어서 cnt 비교하여 거기다 계속 집어 넣는다.

	cout << dist[N-1][N-1] << endl;

	return 0;
}
