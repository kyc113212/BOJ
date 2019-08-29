#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

char map[51][51];
char temp_map[51][51];
int visited[51][51];
int N;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int maxV = 0;
char select_char[] = { 'C','P','Z','Y' };

void copy_map(char origin[][51], char copy[][51]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy[i][j] = origin[i][j];
		}
	}
}

void dfs(int y, int x, char color, int r_c, int count, char arr[51][51]) {
	if (y >= N || x >= N || x < 0 || y < 0)
		return;
	
	maxV = max(maxV, count);
	if (r_c == 0)	//아랫방향으로 이동
	{
		int ny = y + 1;
		if (ny >= N || ny < 0)
			return;
		if (arr[ny][x] == color) {
			if (!visited[ny][x]) {
				visited[ny][x] = true;
				dfs(ny, x, color, r_c, count + 1, arr);
			}
		}
	}
	else if (r_c == 1) {
		int nx = x + 1;
		if (nx >= N || nx < 0)
			return;
		if (arr[y][nx] == color) {
			if (!visited[y][nx]) {
				visited[y][nx] = true;
				dfs(y, nx, color, r_c, count + 1, arr);
			}
		}
	}
}

void solve(int y, int x) {
	//char temp_map[51][51];
	memset(temp_map, 0, sizeof(temp_map));
	copy_map(map, temp_map);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (ny >= N || nx >= N || nx < 0 || ny < 0)
			continue;
		if (visited[ny][nx] == 1)
			continue;
		if (temp_map[ny][nx] != temp_map[y][x]) {
			char temp;
			temp = temp_map[ny][nx];
			temp_map[ny][nx] = temp_map[y][x];
			temp_map[y][x] = temp;
			//여러번 바뀌는듯
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < N; k++) {
					for (int m = 0; m < N; m++) {
						if (temp_map[k][m] == select_char[j]) {
							visited[k][m] = true;
							dfs(k, m, select_char[j], 0, 1, temp_map);
						}
					}
				}
			}
			memset(visited, 0, sizeof(visited));

			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < N; k++) {
					for (int m = 0; m < N; m++) {
						if (temp_map[k][m] == select_char[j]) {
							visited[k][m] = true;
							dfs(k, m, select_char[j], 1, 1, temp_map);
						}
					}
				}
			}
			memset(visited, 0, sizeof(visited));

			temp = temp_map[ny][nx];
			temp_map[ny][nx] = temp_map[y][x];
			temp_map[y][x] = temp;

		}

	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			map[i][j] = s[j];
		}
	}

	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < N; k++) {
			for (int m = 0; m < N; m++) {
				if (map[k][m] == select_char[j]) {
					dfs(k, m, select_char[j], 0, 1, map);
					dfs(k, m, select_char[j], 1, 1, map);
				}
			}
		}
	}



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 1;
			solve(i, j);
		}
	}

	cout << maxV << endl;

	return 0;
}
