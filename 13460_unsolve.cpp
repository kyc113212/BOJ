#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char map[11][11];
int row, col;
int end_x, end_y;
int cnt;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int rdx[] = { 1,-1,0,0 };
int rdy[] = { 0,0,1,-1 };

struct pos {
	int x;
	int y;
	int cnt;
	pos(int a, int b, int c) : x(a), y(b), cnt(c) {}
};

int bfs(queue<pos> &r, queue<pos> &b) {
	while (!r.empty()) {
		//동, 서, 남, 북으로 기울임

		int rx = r.front().x;
		int ry = r.front().y;
		r.pop();

		int bx = b.front().x;
		int by = b.front().y;
		b.pop();

		

		int temp_ry = ry;
		int temp_rx = rx;
		int temp_by = by;
		int temp_bx = bx;
		//이거 위치 지정

		/////////////////////////////
		int c_cnt = r.front().cnt;
		if (c_cnt > 10) {
			continue;
		}
		/////////////////////////////
		//이부분도 위치조정 필요

		for (int i = 0; i < 4; i++) {
			

			while (map[ry][rx] == '.') {
				if (map[ry + rdy[i]][rx + rdx[i]] == '#')
					continue;
				if (map[ry][rx] == 'O') {
					return r.front().cnt + 1;
				}
				if (map[ry][rx] == '#') {
					r.push(pos(ry + rdy[i], rx + rdx[i], cnt + 1));
					break;
				}
				rx += dx[i];
				ry += dy[i];
			}

			ry = temp_ry;
			rx = temp_rx;

			while (map[by][bx] == '.') {
				if (map[by + rdy[i]][bx + rdx[i]] == '#')
					continue;
				if (map[by][bx] == 'O') {
					continue;
				}
				if (map[by][bx] == '#') {
					b.push(pos(ry + rdy[i], rx + rdx[i], cnt + 1));
					break;
				}
				bx += dx[i];
				by += dy[i];
			}

			by = temp_by;
			bx = temp_bx;

		}

	}

	return -1;
}

int main() {

	cin >> row >> col;
	queue<pos> r, b;

	for (int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			scanf("%1c", &map[i][j]);
			if (map[i][j] == 'R')
				r.push(pos(j, i, 0));
			else if (map[i][j] == 'b') {
				b.push(pos(j, i, 0));
			}
			else if (map[i][j] == 'O') {
				i = end_y;
				j = end_x;
			}
		}
	}

	int ans = bfs(r, b);

	return 0;
}
