#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int R, C, T;
int map[51][51];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct pos {
	int x, y;
	pos(int a, int b) : y(a), x(b) {}
};

int check_surround(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= C || ny >= R)
			continue;
		if (map[ny][nx] != -1) {
			cnt++;
		}
	}
	return cnt;
}

int main() {

	cin >> R >> C >> T;

	vector<pos> air;
	queue<pos> dust;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				air.push_back(pos(i, j));
			}
			else if (map[i][j] != 0) {
				dust.push(pos(i, j));
			}
		}
	}

	for (int i = 0; i < T; i++) {
		
		int temp_map[51][51];
		memset(temp_map, 0, sizeof(temp_map));

		while (!dust.empty()) {
			int c_x = dust.front().x;
			int c_y = dust.front().y;
			int c_value = map[c_y][c_x];
			
			dust.pop();

			int surround_space = check_surround(c_y, c_x);
			temp_map[c_y][c_x] += (map[c_y][c_x] - (map[c_y][c_x] / 5) * surround_space);
			for (int j = 0; j < 4; j++) {
				int nx = c_x + dx[j];
				int ny = c_y + dy[j];
				if (nx < 0 || ny < 0 || nx >= C || ny >= R)
					continue;
				if (map[ny][nx] == -1)
					continue;
				temp_map[ny][nx] += (map[c_y][c_x] / 5);
			}
		}


		/*for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] != 0 && map[i][j] != -1) {
					dust.push(pos(i, j));
				}
			}
		}*/
	}



	return 0;
}
