#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

struct pos {
	int y, x, cnt;
	pos(int a, int b, int c) : y(a), x(b), cnt(c) {}
};

char map[1001][1001];
queue<pos> fire;
queue<pos> jihoon;
int R, C;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };




bool check_map(char check_map[1001][1001]) {
	bool flag = false;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (check_map[i][j] == 'J')
				return true;
		}
	}

	return false;
}


int bfs() {

	//char temp_map[1001][1001];
	char count_map[1001][1001];
	memset(count_map, 0, sizeof(count_map));

	while (1) {
		int j_size = jihoon.size();
		int f_size = fire.size();
		memset(count_map, 0, sizeof(count_map));
		if (check_map(map) == false)
			return 0;

		for (int i = 0; i < f_size; i++) {
			int x = fire.front().x;
			int y = fire.front().y;
			int c_cnt = fire.front().cnt;
			fire.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (map[ny][nx] == '#')
					continue;
				if (ny >= R || nx >= C || ny < 0 || nx < 0)
					continue;
				if (map[ny][nx] == '.' || map[ny][nx] == 'J') {
					fire.push(pos(ny, nx, c_cnt + 1));
				}
			}
		}

		for (int i = 0; i < j_size; i++) {
			int x = jihoon.front().x;
			int y = jihoon.front().y;
			int c_cnt = jihoon.front().cnt;
			jihoon.pop();
			
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (map[ny][nx] == '#')
					continue;
				if (ny >= R || nx >= C || nx < 0 || ny < 0)
					return c_cnt + 1;
				if (map[ny][nx] == '.') {
					map[ny][nx] = 'J';
					count_map[ny][nx] = c_cnt + 1;
				}
			}
		}

		

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] == 'J') {
					jihoon.push(pos(i, j, count_map[i][j]));
				}
			}
		}

	}

	return 0;
}

int main() {


	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'J')
				jihoon.push(pos(i, j, 0));
			else if (map[i][j] == 'F')
				fire.push(pos(i, j, 0));
		}
	}

	int rst = bfs();
	if (rst == 0) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << rst << endl;
	}
	
	return 0;
}
