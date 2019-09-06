#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct pos {
	int y, x, camera_type;
	pos(int a, int b, int c) : y(a), x(b), camera_type(c) {}
};

struct value {
	int y, x, dir, camera_type;
	value(int a, int b, int c, int d) : y(a), x(b), dir(c), camera_type(d) {}
};

int cctv_dir1[][4] = { {0,0,0,0}, {1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1} };
int cctv_dir2[][4] = { {0,0,0,0}, {0,1,0,1},{1,0,1,0} };
int cctv_dir3[][4] = { {0,0,0,0}, {1,1,0,0},{0,1,1,0},{0,0,1,1},{1,0,0,1} };
int cctv_dir4[][4] = { {0,0,0,0}, {1,1,1,0},{0,1,1,1},{1,0,1,1},{1,1,0,1} };
int cctv_dir5[][4] = { {0,0,0,0}, {1,1,1,1} };
int N, M;
int map[9][9];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
vector<pos> v;
int minV = 9999;
int visited[9];

void copy_map(int origin_map[][9], int copy[][9]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
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
		if (c_camera_type == 1) {
			for (int j = 0; j < 4; j++) {
				if (cctv_dir1[c_dir][j] == 1) {
					int nx = cx;
					int ny = cy;
					while (1) {
						nx = nx + dx[j];
						ny = ny + dy[j];
						if (ny >= N || nx >= M || nx < 0 || ny < 0)
							break;
						if (temp_map[ny][nx] == 6)
							break;
						if (temp_map[ny][nx] >= 1 && temp_map[ny][nx] <= 4 && temp_map[ny][nx] == 9)
							continue;
						if (temp_map[ny][nx] == 0)
							temp_map[ny][nx] = 9;
					}
				}
			}
		}
		else if (c_camera_type == 2) {
			for (int j = 0; j < 4; j++) {
				if (cctv_dir2[c_dir][j] == 1) {
					int nx = cx;
					int ny = cy;
					while (1) {
						nx = nx + dx[j];
						ny = ny + dy[j];
						if (ny >= N || nx >= M || nx < 0 || ny < 0)
							break;
						if (temp_map[ny][nx] == 6)
							break;
						if (temp_map[ny][nx] >= 1 && temp_map[ny][nx] <= 4 && temp_map[ny][nx] == 9)
							continue;
						if (temp_map[ny][nx] == 0)
							temp_map[ny][nx] = 9;
					}
				}
			}
		}

		else if (c_camera_type == 3) {
			for (int j = 0; j < 4; j++) {
				if (cctv_dir3[c_dir][j] == 1) {
					int nx = cx;
					int ny = cy;
					while (1) {
						nx = nx + dx[j];
						ny = ny + dy[j];
						if (ny >= N || nx >= M || nx < 0 || ny < 0)
							break;
						if (temp_map[ny][nx] == 6)
							break;
						if (temp_map[ny][nx] >= 1 && temp_map[ny][nx] <= 4 && temp_map[ny][nx] == 9)
							continue;
						if (temp_map[ny][nx] == 0)
							temp_map[ny][nx] = 9;
					}
				}
			}
		}

		else if (c_camera_type == 4) {
			for (int j = 0; j < 4; j++) {
				if (cctv_dir4[c_dir][j] == 1) {
					int nx = cx;
					int ny = cy;
					while (1) {
						nx = nx + dx[j];
						ny = ny + dy[j];
						if (ny >= N || nx >= M || nx < 0 || ny < 0)
							break;
						if (temp_map[ny][nx] == 6)
							break;
						if (temp_map[ny][nx] >= 1 && temp_map[ny][nx] <= 4 && temp_map[ny][nx] == 9)
							continue;
						if (temp_map[ny][nx] == 0)
							temp_map[ny][nx] = 9;
					}
				}
			}
		}

		else if (c_camera_type == 5) {
			for (int j = 0; j < 4; j++) {
				if (cctv_dir5[c_dir][j] == 1) {
					int nx = cx;
					int ny = cy;
					while (1) {
						nx = nx + dx[j];
						ny = ny + dy[j];
						if (ny >= N || nx >= M || nx < 0 || ny < 0)
							break;
						if (temp_map[ny][nx] == 6)
							break;
						if (temp_map[ny][nx] >= 1 && temp_map[ny][nx] <= 4 && temp_map[ny][nx] == 9)
							continue;
						if (temp_map[ny][nx] == 0)
							temp_map[ny][nx] = 9;
					}
				}
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp_map[i][j] == 0) {
				cnt++;
			}
		}
	}

	minV = min(minV, cnt);

	return;
}

void select_camera_dir(vector<value> &tv, int idx) {
	if (tv.size() == v.size()) {
		solve(tv);
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		if (visited[i] == false) {
			if (v[i].camera_type == 1) {
				for (int j = 1; j <= 4; j++) {
					visited[i] = true;
					tv.push_back(value(v[i].y, v[i].x, j, v[i].camera_type));
					select_camera_dir(tv, idx + 1);
					tv.pop_back();
					visited[i] = false;
				}
			}
			else if (v[i].camera_type == 2) {
				for (int j = 1; j <= 2; j++) {
					visited[i] = true;
					tv.push_back(value(v[i].y, v[i].x, j, v[i].camera_type));
					select_camera_dir(tv, idx + 1);
					tv.pop_back();
					visited[i] = false;
				}
			}
			else if (v[i].camera_type == 3) {
				for (int j = 1; j <= 4; j++) {
					visited[i] = true;
					tv.push_back(value(v[i].y, v[i].x, j, v[i].camera_type));
					select_camera_dir(tv, idx + 1);
					tv.pop_back();
					visited[i] = false;
				}
			}
			else if (v[i].camera_type == 4) {
				for (int j = 1; j <= 4; j++) {
					visited[i] = true;
					tv.push_back(value(v[i].y, v[i].x, j, v[i].camera_type));
					select_camera_dir(tv, idx + 1);
					tv.pop_back();
					visited[i] = false;
				}
			}
			else if (v[i].camera_type == 5) {
				visited[i] = true;
				tv.push_back(value(v[i].y, v[i].x, 1, v[i].camera_type));
				select_camera_dir(tv, idx + 1);
				tv.pop_back();
				visited[i] = false;
			}
		}
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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

	cout << minV << endl;

	return 0;
}
