#include <iostream>
#include <algorithm>

using namespace std;

struct Fish {
	int y, x, dir;
	bool live;
};

int map[4][4];
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

void move_fish(Fish tf[], int s_y, int s_x) {

	for (int i = 1; i <= 16; i++) {
		if (tf[i].live) {
			int c_dir = tf[i].dir;
			int ny = tf[i].y + dy[c_dir];
			int nx = tf[i].x + dx[c_dir];
			if (ny < 0 || nx < 0 || nx >= 4 || ny >= 4 || ((ny == s_y) && (nx == s_x))) {
				while (can_move(ny,nx,s_y,s_x)) {
									   
					c_dir++;
					if (c_dir == 9)
						c_dir = 1;

					ny = ny + dy[c_dir];
					nx = nx + dx[c_dir];
				}
			}//rotate 완료
			//swap시작
			Fish temp;
			temp.y = tf[i].y;
			tf[i].y = ny;
			ny = temp.y;

			temp.x = tf[i].x;
			tf[i].x = nx;
			nx = temp.x;

			temp.dir = tf[i].dir;
		}
	
	}

}

void move_shark(Fish ff[], int s_y, int s_x, int s_cnt) {
	ans = max(ans, s_cnt);

	move_fish(ff,s_y,s_x);

	move_shark(); //각 case 모두 이동
	
}

int main() {

	Fish fish[17];
	int cnt = 0;
	for (int i = 1; i <= 16; i++) {
		int a, b;
		cin >> a >> b;
		fish[a].dir = b;
		fish[a].live = true;
		fish[a].y = cnt;
		fish[a].x = i % 4;
		map[cnt][(i - 1) % 4] = a;
		
		if (i % 4 == 0)
			cnt++;

	}

	fish[map[0][0]].live = false;
	move_shark(fish, 0, 0, map[0][0]);

	

	return 0;
}
