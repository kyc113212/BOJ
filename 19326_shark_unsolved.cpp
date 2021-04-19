#include <iostream>
#include <algorithm>

using namespace std;

struct Fish {
	int y, x, dir;
	bool live;
};

int ans = 0;
int dx[] = { 0,0,-1,-1,-1,0,1,1,1 };
int dy[] = { 0,-1,-1,0,1,1,1,0,-1 };

int rotate_fish(int dir,Fish tf[]) {
	dir = dir + 1;
	if (dir == 9)
		dir = 1;
	return dir;
}

bool can_move(int ny, int nx, int s_y, int s_x) {
	
	if (ny < 0 || nx < 0 || nx >= 4 || ny >= 4 || ((ny == s_y) && (nx == s_x)))
		return true;

	return false;

}

void move_fish(Fish tf[], int s_y, int s_x, int tm[][4]) {

	for (int i = 1; i <= 16; i++) {
		if (tf[i].live) {
			int c_dir = tf[i].dir;
			int cy = tf[i].y;
			int cx = tf[i].x; 
			bool c_live = tf[i].live;
			int ny = cy + dy[c_dir];
			int nx = cx + dx[c_dir];
			if (ny < 0 || nx < 0 || nx >= 4 || ny >= 4 || ((ny == s_y) && (nx == s_x))) {
				while (can_move(ny,nx,s_y,s_x)) {
													   
					c_dir++;
					if (c_dir == 9)
						c_dir = 1;

					ny = cy + dy[c_dir];
					nx = cx + dx[c_dir];
				}
			}//rotate 완료
			//swap시작
			int change_fish_num = tm[ny][nx];
			tm[ny][nx] = tm[cy][cx];
			tm[cy][cx] = change_fish_num;

			Fish temp_f = tf[change_fish_num];
			tf[change_fish_num].dir = temp_f.dir;
			tf[change_fish_num].y = cy;
			tf[change_fish_num].x = cx;
			tf[change_fish_num].live = temp_f.live;

			tf[i].dir = c_dir;
			tf[i].x = nx;
			tf[i].y = ny;
			tf[i].live = c_live;
			int a = 1;
		}
	
	}

}

void move_shark(Fish ff[], int s_y, int s_x, int s_cnt, int tm[][4], int shark_dir) {
	
	ans = max(ans, s_cnt);

	move_fish(ff,s_y,s_x, tm);

	for (int i = 0; i < 4; i++) {
		int ny = s_y + dy[shark_dir] * i;
		int nx = s_x + dx[shark_dir] * i;
		if (ny < 0 || nx < 0 || nx >= 4 || ny >= 4)
			continue;
		if (ff[tm[ny][nx]].live == false)
			continue;
		ff[tm[ny][nx]].live = false;
		shark_dir = ff[tm[ny][nx]].dir;
		move_shark(ff, ny, nx, s_cnt + tm[ny][nx], tm, shark_dir);
		ff[tm[ny][nx]].live = true;
	}

	return;
	//move_shark(); //각 case 모두 이동
	
}

int main() {

	Fish fish[17];
	int map[4][4];
	memset(map, 0, sizeof(map));
	int cnt = 0;
	for (int i = 1; i <= 16; i++) {
		int a, b;
		cin >> a >> b;
		fish[a].dir = b;
		fish[a].live = true;
		fish[a].y = cnt;
		fish[a].x = (i - 1) % 4;
		map[cnt][(i - 1) % 4] = a;
		
		if (i % 4 == 0)
			cnt++;
	}

	fish[map[0][0]].live = false;
	int shark_dir = fish[map[0][0]].dir;
	move_shark(fish, 0, 0, map[0][0], map, shark_dir);

	cout << ans << endl;

	return 0;
}
