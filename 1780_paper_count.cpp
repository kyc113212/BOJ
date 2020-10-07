#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int map[2200][2200];
int check_1[2200][2200];
int visited[2200][2200];
int N;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int minus_cnt;
int zero_cnt;
int plus_cnt;

int main() {

	memset(map, 0, sizeof(map));

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i += 3) {
		for (int j = 0; j < N; j += 3) {

			int pivot_value = map[i][j];
			bool flag = false;
			for (int m = i; i < i + 3; m++) {
				for (int n = j; j < j + 3; n++) {
					if (pivot_value != map[m][n]) {
						flag = true;
					}
				}
			}

			if (flag == false) {
				for (int m = i; i < i + 3; m++) {
					for (int n = j; j < j + 3; n++) {
						check_1[m][n] = 1;	//1이면 한개인 경우
					}
				}
			}

		}
	}

	for (int i = 0; i < N; i += 3) {
		int prev = 0;
		int j = 0;
		for (j = 0; j < N; j += 3) {
			if (check_1[i][j] == 1)
				continue;
			if (check_1[i][j] == 0) {
				int max_row = 0;
				for (int m = i; m < N; m++) {
					if (check_1[m][j] == 1 || map[i][j] != map[m][j]) {
						max_row = m - 1;
						break;
					}
				}

				int max_column = 0;
				for (int m = j; m < N; m++) {
					if (check_1[i][m] == 1 || map[i][j] != map[i][m]) {
						max_column = m - 1;
						break;
					}
				}

				if (max_row - i < 8 || max_column - j < 8) {	// 3X3인 종이들
					for (int m = i; m <= max_row; m++) {
						for (int n = j; n <= max_column; n++) {
							check_1[m][n] = 2;	//2이면 숫자는 같지만 3X3인 경우
						}
					}
				}
				else {
					//범위 내 값이 모두 같은값인지 확인
					bool flag = false;
					for (int m = i; m <= max_row; m++) {
						for (int n = j; j <= max_column; n++) {
							if (map[i][j] != map[m][n]) {
								flag = true;
								break;
							}
						}
					}
					int range = max(max_row - i, max_column - j);
					if (flag == false) {
						for (int m = i; m <= range; m++) {
							for (int n = j; j <= range; n++) {
								check_1[m][n] = 3;	//3이상이면 9x9이상인 종이
							}
						}
					}
				}

			}
		}
	}





	return 0;
}
