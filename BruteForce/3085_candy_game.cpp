#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

char map[51][51];
int visited[51][51];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int ans = 1;
int N;

int change_right(int y, int x) {
	int maxV = 0;
	char temp = map[y][x];
	map[y][x] = map[y][x + 1];
	map[y][x + 1] = temp;

	//한 행, 바뀐 두 열 check
	for (int j = 0; j < N - 1; j++) {
		ans = 1;
		if (map[y][j] == map[y][j + 1]) {
			int k = j;
			for (k = j; k < N - 1; k++) {
				if (map[y][k] == map[y][k + 1]) {
					ans++;
				}
				else
					break;
			}
			j = k;
		}
		maxV = max(maxV, ans);
	}

	for (int i = x; i < x+2; i++) {
		for (int j = 0; j < N - 1; j++) {
			ans = 1;
			if (map[j][i] == map[j + 1][i]) {
				int k = j;
				for (k = j; k < N - 1; k++) {
					if (map[k][i] == map[k + 1][i]) {
						ans++;
					}
					else
						break;
				}
				j = k;
			}
			maxV = max(maxV, ans);
		}
	}
	

	temp = map[y][x];
	map[y][x] = map[y][x + 1];
	map[y][x + 1] = temp;

	return maxV;
}

int change_down(int y, int x) {
	int maxV = 0;
	char temp = map[y][x];
	map[y][x] = map[y+1][x];
	map[y+1][x] = temp;
	memset(visited, 0, sizeof(visited));

	//두행, 한 열 check
	for (int j = 0; j < N - 1; j++) {
		ans = 1;
		if (map[j][x] == map[j+1][x]) {
			int k = j;
			for (k = j; k < N - 1; k++) {
				if (map[k][x] == map[k+1][x]) {
					ans++;
				}
				else
					break;
			}
			j = k;
		}
		maxV = max(maxV, ans);
	}

	for (int i = y; i < y + 2; i++) {
		for (int j = 0; j < N - 1; j++) {
			ans = 1;
			if (map[i][j] == map[i][j+1]) {
				int k = j;
				for (k = j; k < N - 1; k++) {
					if (map[i][k] == map[i][k+1]) {
						ans++;
					}
					else
						break;
				}
				j = k;
			}
			maxV = max(maxV, ans);
		}
	}

	temp = map[y][x];
	map[y][x] = map[y+1][x];
	map[y+1][x] = temp;

	return maxV;
}

int main() {

	cin >> N;
	int maxV = 0;
	char colr_arry[] = { 'C', 'P', 'Z', 'Y' };
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			map[i][j] = s[j];
		}
	}

	//바꾸지 않고 제일 큰값 확인
	//행이 같은경우
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
			ans = 1;
			if (map[i][j] == map[i][j + 1]) {
				int k = j;
				for (k = j; k < N-1; k++) {
					if (map[i][k] == map[i][k + 1]) {
						ans++;
					}
					else
						break;
				}
				j = k;
			}
			maxV = max(maxV, ans);
		}
	}

	//열이 같은 경우
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			ans = 1;
			if (map[j][i] == map[j+1][i]) {
				int k = j;
				for (k = j; k < N - 1; k++) {
					if (map[k][i] == map[k+1][i]) {
						ans++;
					}
					else
						break;
				}
				j = k;
			}
			maxV = max(maxV, ans);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
			//우 바꾼 후 갯수 확인
			maxV = max(maxV, change_right(i, j));
		}
	}
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < N; j++) {
			//하 바꾼 후 갯수 확인
			maxV = max(maxV, change_down(i, j));
		}
	}


	cout << maxV << endl;

	return 0;
}
