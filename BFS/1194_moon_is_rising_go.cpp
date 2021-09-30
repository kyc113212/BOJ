#include <iostream>
#include <queue>
#include <cstring>
#include <deque>
#include <string>

using namespace std;
//달이 차오른다 가자

struct pos {
	int y, x, cnt;
	int key;
	pos(int a, int b, int c, int d) : y(a), x(b), cnt(c), key(d) {}
};

int get_key[6];
int N, M;
char map[51][51];
deque<pos> q;
deque<pos> key, door[6];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int endy, endx;

bool check_range(int y, int x) {
	return 0 <= y && 0 <= x && N > y && M > x;
}

int bfs() {

	int visited[51][51][1 << 6];
	memset(visited, 0, sizeof(visited));
	visited[q[0].y][q[0].x][0] = 1;

	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		int c_cnt = q.front().cnt;
		int c_key = q.front().key;
		q.pop_front();

		if (map[cy][cx] == '1')
			return c_cnt;

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (!check_range(ny, nx))
				continue;
			if (visited[ny][nx][c_key])
				continue;
			if (map[ny][nx] == '.' || map[ny][nx] == '1') {
				visited[ny][nx][c_key] = 1;
				q.push_back(pos(ny, nx, c_cnt + 1, c_key));
			}
			else if (map[ny][nx] >= 'a' && map[ny][nx] <= 'f') {//key가지게 한다.
				int n_key = c_key | (1 << int(map[ny][nx]) - 97);
				visited[ny][nx][n_key] = 1;
				q.push_back(pos(ny, nx, c_cnt + 1, n_key));
			}
			else if (map[ny][nx] >= 'A' && map[ny][nx] <= 'F') {
				if ((c_key & 1 << int(map[ny][nx] - 'A')) != 0) { //key를 가지고 있는것
					visited[ny][nx][c_key] = 1;
					q.push_back(pos(ny, nx, c_cnt + 1, c_key));
				}
			}
		}
	}
	
	return -1;
}

int main() {

	cin >> N >> M;
	/*for (int i = 0; i < 6; i++) {
		door.push_back(pos(0, 0, 0));
		key.push_back(pos(0, 0, 0));
	}*/
	

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s[j];
			if (map[i][j] == '0') {
				map[i][j] = '.';
				q.push_back(pos(i, j, 0, 0));
			}
			if (map[i][j] == '1') {
				endx = j;
				endy = i;
			}

		}
	}

	cout << bfs() << endl;



	return 0;
}
