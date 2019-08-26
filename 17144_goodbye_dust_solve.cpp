#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int R, C, T;
int map[52][52];
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

void copy_map(int origin[][52], int copy[][52]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			copy[i][j] = origin[i][j];
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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
				//if (map[i][j] == 1)
					//continue;
				dust.push(pos(i, j));
			}
		}
	}

	for (int i = 0; i < T; i++) {

		int temp_map[52][52];
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


		int temp_y = air[0].y;
		int temp1 = 0;
		int temp2 = 0;
		int t = 0;
		temp1 = temp_map[temp_y][t];
		temp2 = temp_map[temp_y][t + 1];
		while (t < C - 1) {
			temp_map[temp_y][t + 1] = temp1;
			temp1 = temp2;
			t++;
			temp2 = temp_map[temp_y][t + 1];
		}

		t = temp_y;
		temp2 = temp_map[t - 1][C - 1];
		while (t > 0) {
			temp_map[t - 1][C - 1] = temp1;
			temp1 = temp2;
			t--;
			temp2 = temp_map[t - 1][C - 1];
		}

		t = C - 1;
		temp2 = temp_map[0][C - 2];
		while (t > 0) {
			temp_map[0][t - 1] = temp1;
			temp1 = temp2;
			t--;
			temp2 = temp_map[0][t - 1];
		}

		t = 0;
		temp2 = temp_map[t+1][0];
		while (t < temp_y - 1) {
			temp_map[t + 1][0] = temp1;
			temp1 = temp2;
			t++;
			temp2 = temp_map[t + 1][0];
		}


		temp_y = air[1].y;
		temp1 = 0;
		temp2 = 0;
		t = 0;
		temp1 = temp_map[temp_y][t];
		temp2 = temp_map[temp_y][t + 1];
		while (t < C - 1) {
			temp_map[temp_y][t + 1] = temp1;
			temp1 = temp2;
			t++;
			temp2 = temp_map[temp_y][t + 1];
		}

		t = temp_y;
		temp2 = temp_map[t + 1][C - 1];
		while (t < R - 1) {
			temp_map[t + 1][C - 1] = temp1;
			temp1 = temp2;
			t++;
			temp2 = temp_map[t + 1][C - 1];
		}

		t = C - 1;
		temp2 = temp_map[R - 1][t - 1];
		while (t > 0) {
			temp_map[R-1][t - 1] = temp1;
			temp1 = temp2;
			t--;
			temp2 = temp_map[R-1][t - 1];
		}

		t = R-1;
		temp2 = temp_map[t - 1][0];
		while (t > temp_y + 1) {
			temp_map[t - 1][0] = temp1;
			temp1 = temp2;
			t--;
			temp2 = temp_map[t - 1][0];
		}


		temp_map[air[0].y][air[0].x] = -1;
		temp_map[air[1].y][air[1].x] = -1;

		copy_map(temp_map, map);

		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				if (map[j][k] != 0 && map[j][k] != -1) {
					dust.push(pos(j, k));
				}
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			ans += map[i][j];
		}
	}

	ans = ans + 2;
	cout << ans << endl;


	return 0;
}
