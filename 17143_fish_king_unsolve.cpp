#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>;

using namespace std;

struct pos {
	//int y, x;
	int exist;
	int speed, direction;
	int mass;
	int move;
	pos(int a, int c, int d, int e, int f) : exist(a), speed(c), direction(d), mass(e), move(f) {}
};

int row, col, M;
int map[8][8];
vector<pos> v[101];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };

int main() {

	cin >> row >> col >> M;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			v[i].push_back(pos(0,0, 0, 0,0));
		}
	}

	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		r = r - 1;
		c = c - 1;
		v[r][c].speed = s;
		v[r][c].exist = 1;
		v[r][c].direction = d;
		v[r][c].mass = z;
		v[r][c].move = 0;
		map[r][c] = d;
		//v.push_back(pos(r, c, s, d, z));
	}

	int col_cnt = 0;
	int mass_count = 0;

	while (col > col_cnt) {

		for (int i = 0; i < col; i++) {
			if (v[i][col_cnt].exist == 1) {
				mass_count += v[i][col_cnt].mass;
				v[i][col_cnt].exist = 0;
				v[i][col_cnt].speed = 0;
				v[i][col_cnt].direction = 0;
				v[i][col_cnt].mass = 0;
				v[i][col_cnt].move = 0;
				map[i][col_cnt] = 0;
				break;
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (v[i][j].exist == 1 && v[i][j].move == 0) {
					int c_y = i;
					int c_x = j;
					int c_d = v[c_y][c_x].direction;
					int c_speed = v[c_y][c_x].speed;
					int c_m = v[c_y][c_x].mass;
					bool flag = false;
					while (flag == false) {
						int n_y = c_y;
						int n_x = c_x;
						int n_d = c_d;
						int n_speed = c_speed;
						int n_mass = c_m;
						for (int k = 0; k < n_speed; k++) {
							n_y += dy[n_d];
							n_x += dx[n_d];
							if (n_y == -1) {
								n_y = 1;
								n_d = 2;
							}
							else if (n_y == row) {
								n_y = row - 2;
								n_d = 1;
							}
							else if (n_x == col) {
								n_x = col - 2;
								n_d = 4;
							}
							else if (n_x == -1) {
								n_x = 1;
								n_d = 3;
							}
						}

						if (v[n_y][n_x].exist == 0) {
							v[n_y][n_x].exist = 1;
							v[n_y][n_x].direction = n_d;
							v[n_y][n_x].mass = v[c_y][c_x].mass;
							v[n_y][n_x].speed = v[c_y][c_x].speed;
							v[n_y][n_x].move = 1;
							map[n_y][n_x] = n_d;

							v[c_y][c_x].exist = 0;
							v[c_y][c_x].direction = 0;
							v[c_y][c_x].mass = 0;
							v[c_y][c_x].speed = 0;
							map[c_y][c_x] = 0;
							flag = true;
						}
						else if (v[n_y][n_x].move == 0 && v[n_y][n_x].exist == 1) {	//이동한 곳에 이동안한 상어가 있는경우.
							if (n_y == c_y && n_x == c_x) {
								v[n_y][n_x].exist = v[c_y][c_x].exist;
								v[n_y][n_x].direction = n_d;
								v[n_y][n_x].mass = v[c_y][c_x].mass;
								v[n_y][n_x].speed = v[c_y][c_x].speed;
								v[n_y][n_x].move = 1;
								map[n_y][n_x] = n_d;
								flag = true;
							}
							else {
								int temp_dir = v[n_y][n_x].direction;
								int temp_y = n_y;
								int temp_x = n_x;
								int temp_speed = n_speed;
								int temp_mass = n_mass;
								//돌아온게 자기 자신인경우
								v[n_y][n_x].exist = v[c_y][c_x].exist;
								v[n_y][n_x].direction = n_d;
								v[n_y][n_x].mass = v[c_y][c_x].mass;
								v[n_y][n_x].speed = v[c_y][c_x].speed;
								v[n_y][n_x].move = 1;
								map[n_y][n_x] = n_d;
								//vector<pos> temp_v = v[n_y];
								c_y = temp_y;
								c_x = temp_x;
								c_speed = temp_speed;
								c_d = temp_dir;
								c_m = temp_mass;
							}							
						}
						else if (v[n_y][n_x].move == 1) {	//이동한곳에 이동한 상어가 있는경우
							if (v[n_y][n_x].mass < v[c_y][c_x].mass) { //이동한 상어가 더 큰경우
								v[n_y][n_x].exist = v[c_y][c_x].exist;
								v[n_y][n_x].direction = n_d;
								v[n_y][n_x].mass = v[c_y][c_x].mass;
								v[n_y][n_x].speed = v[c_y][c_x].speed;
								v[n_y][n_x].move = 1;
								map[n_y][n_x] = n_d;

								v[c_y][c_x].exist = 0;
								v[c_y][c_x].direction = 0;
								v[c_y][c_x].mass = 0;
								v[c_y][c_x].speed = 0;
								map[c_y][c_x] = 0;
							}
							else {	//이동한 상어가 먹힘
								v[c_y][c_x].exist = 0;
								v[c_y][c_x].direction = 0;
								v[c_y][c_x].mass = 0;
								v[c_y][c_x].speed = 0;
								map[c_y][c_x] = 0;
							}
							flag = true;
						}
					}				
				}
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				v[i][j].move = 0;
			}
		}

		col_cnt++;
	}

	cout << mass_count << endl;

	return 0;
}
