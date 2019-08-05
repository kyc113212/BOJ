#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct item {
	int num, cnt;
	item(int a, int b) : num(a), cnt(b) {}
};

vector<item> v[100];

int main()
{
	int row, col, k;
	int map[101][101];
	memset(map, 0, sizeof(map));
	cin >> row >> col >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}
	int cnt = 0;
	int ans = 0;
	int max_row = 3;
	int max_col = 3; 

	while (1) {
		if (map[row][col] != 0) {
			ans = map[row][col];
			break;
		}
		else if (cnt > 100) {
			ans = -1;
			break;
		}

		if (max_row >= max_col) {	//R연산 -> 오른쪽으로 증가
			for (int i = 0; i < max_row; i++) {
				for (int j = 0; j < max_col; j++) {

				}
			}

		}
		else if(max_row < max_col) {	//C연산 -> 아래로 증가

		}

		

		cnt++;
	}



	return 0;
}
