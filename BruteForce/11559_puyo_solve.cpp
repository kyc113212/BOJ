#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char map[12][6];
int visited[12][6];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool count_flag = false;
int solve_count;

void rearrange_map() {
	int temp_y = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 11; j >= 0; j--) {
			if (map[j][i] == '.') {
				temp_y = j;
				for (int k = temp_y; k >= 0; k--) {
					if (map[k][i] != '.') {
						map[temp_y][i] = map[k][i];
						map[k][i] = '.';
						break;
					}
				}
			}

		}
	}
}

bool check_map_count(char color) {
	int count = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 11; j >= 0; j--) {
			if (map[j][i] == color && visited[j][i] == 1)
				count++;
		}
	}
	if (count >= 4)
		return true;
	else
		return false;
}

void dfs(int y, int x, int cnt, char color) {
	if (check_map_count(color) == true) {
		bool color_check = false;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < 12 && nx >= 0 && nx < 6 && !visited[ny][nx] && map[ny][nx] == color) {
				color_check = true;
			}
		}
		if (color_check == true) {
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny >= 0 && ny < 12 && nx >= 0 && nx < 6 && !visited[ny][nx] && map[ny][nx] == color) {
					visited[ny][nx] = 1;
					dfs(ny, nx, cnt + 1, color);
					//visited[ny][nx] = 0;
				}
			}
		}
		else if (color_check == false) {
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 6; j++) {
					if (visited[i][j] == 1) {
						map[i][j] = '.';
					}
				}
			}
			solve_count++;
			return;
		}

	}
	else {
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < 12 && nx >= 0 && nx < 6 && !visited[ny][nx] && map[ny][nx] == color) {
				visited[ny][nx] = 1;
				dfs(ny, nx, cnt + 1, color);
				//visited[ny][nx] = 1;
			}
		}
	}

}

int main() {

	int cnt = 0;
	int ans = 0;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}


	rearrange_map();

	while (1) {
		solve_count = 0;

		for (int i = 0; i < 6; i++) {
			for (int j = 11; j >= 0; j--) {
				if (map[j][i] != '.') {
					visited[j][i] = 1;
					dfs(j, i, 1, map[j][i]);
					memset(visited, 0, sizeof(visited));
				}
			}
		}
		if (solve_count == 0) {
			if (cnt == 0) {
				ans = 0;
				break;
			}
			else {
				ans = cnt;
				break;
			}
		}
		cnt++;
		rearrange_map();
	}

	cout << ans << endl;

	return 0;
}
