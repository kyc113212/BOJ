#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int row, col;
int map[9][9];
int temp_map[9][9];
int visited[9];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int minValue = 9999;

struct pos {
	int x, y;
	int value;
	pos(int a, int b,int c) : y(a), x(b), value(c) {}
};

int solve(vector<pos>& tv) {

	int ans = 0;

	for (int i = 0; i < tv.size(); i++) {
		int c_y = tv[i].y;
		int c_x = tv[i].x;
		int c_value = tv[i].value;
		int cnt1 = -9999;
		int cnt2 = -9999;
		int cnt3 = -9999;
		int cnt4 = -9999;
		int cnt5 = -9999;
		if (c_value == 1) {
			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				int n_x = c_x + dx[j];
				int n_y = c_y + dy[j];
				while (1) {
					if (n_y >= row || n_x >= col || n_x < 0 || n_y < 0) {
						break;
					}
					if (map[n_y][n_x] != 6) {
						n_x += dx[j];
						n_y += dy[j];
						cnt++;
					}
					else if (map[n_y][n_x] == 6) {
						break;
					}
				}
				if (cnt1 < cnt) {
					cnt1 = cnt;
					memset(temp_map, 0, sizeof(temp_map));
					int t_x = c_x + dx[j];
					int t_y = c_y + dy[j];
					while (1) {
						if (t_y >= row || t_x >= col || t_x < 0 || t_y < 0) {
							break;
						}
						if (map[t_y][t_x] == 6) {
							break;
						}
						if (map[t_y][t_x] == 0){
							temp_map[t_y][t_x] = 7;
						}
						t_x += dx[j];
						t_y += dy[j];
					}
				}
			}
		}
		else if (c_value == 2) {

		}
	}

	return 0;
}


int main() {

	cin >> row >> col;
	vector<pos> v,temp_v;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			temp_map[i][j] = map[i][j];
			if (map[i][j] != 0)
				v.push_back(pos(i, j,map[i][j]));
		}
	}

	solve(v);



	return 0;
}
