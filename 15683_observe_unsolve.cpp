#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct pos {
	int y, x, camera_type;
	pos(int a, int b,int c) : y(a), x(b), camera_type(c) {}
};

struct value {
	int y, x, dir, camera_type;
	value(int a, int b, int c, int d) : y(a), x(b), dir(c), camera_type(d) {}
};

int cctv_dir1[][4] = { {1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
int cctv_dir2[][4] = { {0,1,0,1},{1,0,1,0}};
int cctv_dir3[][4] = { {1,1,0,0},{0,1,1,0},{0,0,1,1},{1,0,0,1} };
int cctv_dir4[][4] = { {1,1,1,0},{0,1,1,1},{1,0,1,1},{1,1,0,1} };
int cctv_dir5[][4] = { {1,1,1,1} };
int N, M;
int map[9][9];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
vector<pos> v;

void copy_map(int origin_map[][9], int copy[][9]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy[i][j] = origin_map[i][j];
		}
	}
}

void solve(vector<value>& tv) {
	int temp_map[9][9];
	memset(temp_map, 0, sizeof(temp_map));
	copy_map(map, temp_map);

	for (int i = 0; i < tv.size(); i++) {
		int cx = tv[i].x;
		int cy = tv[i].y;
		int c_dir = tv[i].dir;
		int c_camera_type = tv[i].camera_type;
		if (c_dir == 1) {
		}
	}


	return;
}

void select_camera_dir(vector<value> &tv, int idx) {
	if (tv.size() == v.size()) {
		solve(tv);
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		if (v[i].camera_type == 1) {
			for (int j = 0; j < 4; j++) {
				tv.push_back(value(v[i].y, v[i].x, j, v[i].camera_type));
				select_camera_dir(tv, idx + 1);
				tv.pop_back();
			}
		}
		else if (v[i].camera_type == 2) {
			for (int j = 0; j < 2; j++) {
				tv.push_back(value(v[i].y, v[i].x, j, v[i].camera_type));
				select_camera_dir(tv, idx + 1);
				tv.pop_back();
			}
		}
		else if (v[i].camera_type == 3) {
			for (int j = 0; j < 4; j++) {
				tv.push_back(value(v[i].y, v[i].x, j, v[i].camera_type));
				select_camera_dir(tv, idx + 1);
				tv.pop_back();
			}
		}
		else if (v[i].camera_type == 4) {
			for (int j = 0; j < 4; j++) {
				tv.push_back(value(v[i].y, v[i].x, j, v[i].camera_type));
				select_camera_dir(tv, idx + 1);
				tv.pop_back();
			}
		}
		else if (v[i].camera_type == 5) {
			tv.push_back(value(v[i].y, v[i].x, 0, v[i].camera_type));
			select_camera_dir(tv, idx + 1);
			tv.pop_back();
		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				v.push_back(pos(i, j, map[i][j]));
			}
		}
	}

	vector<value> tv;
	select_camera_dir(tv, 0);

	return 0;
}
