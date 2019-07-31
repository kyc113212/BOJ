#include <iostream>

using namespace std;

int map[21][21];
int dice[7];
int arr_cmd[1001];
int cur_bottom_pos;
int cur_top;

int main() {

	int row, col;
	int x, y;
	int cmd;

	cin >> row >> col >> x >> y >> cmd;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < cmd; i++) {
		cin >> arr_cmd[i];
	}

	int cur_x = x;
	int cur_y = y;
	cur_bottom_pos = 6;

	for (int i = 0; i < cmd; i++) {
		int next_x = 0;
		int next_y = 0;

		if (arr_cmd[i] == 1) {
			next_x = cur_x + 1;
		}
		else if (arr_cmd[i] == 2) {
			next_x = cur_x - 1;
		}
		else if (arr_cmd[i] == 3) {
			next_y = cur_y - 1;
		}
		else if (arr_cmd[i] == 4) {
			next_y = cur_y + 1;
		}

		if (next_y < 0 || next_x < 0 || next_x >= col || next_y >= row)
			continue;
		


		cur_x = next_x;
		cur_y = next_y;

	}

	return 0;
}
