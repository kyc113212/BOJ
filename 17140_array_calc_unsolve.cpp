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
	int visited[101][101];
	memset(map, 0, sizeof(map));
	memset(visited, 0, 0);
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
		if (map[row][col] == k) {
			ans = cnt;
			break;
		}
		else if (cnt > 100) {
			ans = -1;
			break;
		}

		if (max_row >= max_col) {	//R연산 -> 오른쪽으로 증가
			for (int i = 0; i < max_row; i++) {
				v[i].push_back(item((map[i][0]), 1));
				//visited[i][0] = true;
				for (int j = 1; j < max_col; j++) {
					for (int k = 0; k < v[i].size(); k++) {
						if (v[i][k].num == map[i][j]) {
							v[i][j].cnt++;
						}
						else {
							v[i].push_back(item((map[i][j]), 1));
						}
					}
				}
			}

		}
		else if (max_row < max_col) {	//C연산 -> 아래로 증가

		}



		cnt++;
	}



	return 0;
}
