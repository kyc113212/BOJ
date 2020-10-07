#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int map[2200][2200];
int check_1[2200][2200];
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
						check_1[m][n] = 1;	//1개의 값
					}
				}
			}

		}
	}

	for (int i = 0; i < N; i += 3) {
		int prev = 0;
		int j = 0;
		for (j = 0; j < N; j += 3) {
			if (map[i][prev] != map[i][j])
				break;
		}
		if()
	}


	


	return 0;
}
