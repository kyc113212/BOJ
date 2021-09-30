#include <iostream>
#include <cstring>

using namespace std;

int R, C, X, Y, M;
int dx[] = { 0,1,-1,0,0 };
int dy[] = { 0,0,0,-1,1 };
int map[21][21];
int cmd[1001];
int dice[7];
int copy_dice[7];

void copy_map(int *original_arr, int *copy_arr) {
	for (int i = 1; i <= 6; i++) {
		copy_arr[i] = original_arr[i];
	}
	return;
}


int main() {

	cin >> R >> C >> Y >> X >> M;
	memset(map, 0, sizeof(map));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> cmd[i];
	}

	int cur_top = 6;
	int cur_y = Y;
	int cur_x = X;
	for (int i = 0; i < M; i++) {
		
		cur_y = cur_y + dy[cmd[i]];
		cur_x = cur_x + dx[cmd[i]];
		if (cur_y < 0 || cur_x < 0 || cur_y >= R || cur_x >= C) {
			cur_y -= dy[cmd[i]];
			cur_x -= dx[cmd[i]];
			continue;
		}
		
		if (cmd[i] == 1) {
			copy_dice[1] = dice[3];
			copy_dice[3] = dice[6];
			copy_dice[6] = dice[4];
			copy_dice[4] = dice[1];
		}
		else if (cmd[i] == 2) {
			copy_dice[6] = dice[3];
			copy_dice[4] = dice[6];
			copy_dice[1] = dice[4];
			copy_dice[3] = dice[1];
		}
		else if (cmd[i] == 3) {
			copy_dice[6] = dice[2];
			copy_dice[2] = dice[1];
			copy_dice[1] = dice[5];
			copy_dice[5] = dice[6];
		}
		else if (cmd[i] == 4) {
			copy_dice[1] = dice[2];
			copy_dice[5] = dice[1];
			copy_dice[6] = dice[5];
			copy_dice[2] = dice[6];
		}

		cout << copy_dice[6] << endl;
		//memset(dice, 0, sizeof(dice));
		copy_map(copy_dice, dice);

		if (map[cur_y][cur_x] == 0) {
			map[cur_y][cur_x] = dice[1];
		}
		else {
			dice[1] = map[cur_y][cur_x];
			map[cur_y][cur_x] = 0;
		}

		//memset(copy_dice, 0, sizeof(copy_dice));

		//마지막에 맨위 숫자 표시
	}

	return 0;
}
