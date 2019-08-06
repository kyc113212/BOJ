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

bool comp(item& v1, item& v2) {
	if (v1.cnt == v2.cnt) {
		return v1.num < v2.num;
	}
	else {
		return v1.cnt < v2.cnt;
	}
}

int main()
{
	int row, col, k;
	int map[101][101];
	bool visited[101];
	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));
	cin >> row >> col >> k;
	row = row - 1;
	col = col - 1;
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
				for (int j = 0; j < max_col; j++) {
					if (map[i][j] == 0) {
						continue;
					}
					if (visited[map[i][j]] == false) {
						visited[map[i][j]] = true;
						v[i].push_back(item(map[i][j], 1));
					}
					else {
						for (int k = 0; k < v[i].size(); k++) {
							if (map[i][j] == v[i][k].num) {
								v[i][k].cnt++;
							}
						}
					}
				}
				memset(visited, false, sizeof(visited));
			}
			memset(map, 0, sizeof(map));
			for (int i = 0; i < max_row; i++) {
				sort(v[i].begin(), v[i].end(), comp);
			}

			max_col = 0;
			for (int i = 0; i < max_row; i++) {
				int x_value = 0;
				for (int j = 0; j < v[i].size(); j++) {
					map[i][x_value] = v[i][j].num;
					x_value++;
					map[i][x_value] = v[i][j].cnt;
					x_value++;
				}
				max_col = max(max_col, x_value);
			}
			for (int i = 0; i < max_row; i++) {
				v[i].clear();
			}
		}

		else if (max_row < max_col) {	//C연산 -> 아래로 증가
			for (int i = 0; i < max_col; i++) {
				for (int j = 0; j < max_row; j++) {
					if (map[j][i] == 0) {
						continue;
					}
					if (visited[map[j][i]] == false) {
						visited[map[j][i]] = true;
						v[i].push_back(item(map[j][i], 1));
					}
					else {
						for (int k = 0; k < v[i].size(); k++) {
							if (map[j][i] == v[i][k].num) {
								v[i][k].cnt++;
							}
						}
					}
				}
				memset(visited, false, sizeof(visited));
			}
			memset(map, 0, sizeof(map));
			for (int i = 0; i < max_col; i++) {
				sort(v[i].begin(), v[i].end(), comp);
			}

			max_row = 0;
			for (int i = 0; i < max_col; i++) {
				int y_value = 0;
				for (int j = 0; j < v[i].size(); j++) {
					map[y_value][i] = v[i][j].num;
					y_value++;
					map[y_value][i] = v[i][j].cnt;
					y_value++;
				}
				max_row = max(max_row, y_value);
			}

			for (int i = 0; i < max_col; i++) {
				v[i].clear();
			}
		}

		cnt++;

		
	}

	cout << ans << endl;


	return 0;
}
