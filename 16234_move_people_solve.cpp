#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N, over, under;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int cnt;

int map[51][51];
int visited[51][51];
int check_map_sum[2001];
int check_map_cnt[2001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> over >> under;

	bool check = true;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	//구역을 나눠야함
	while (check == true) {
		check = false;
		int visit_count = 0;
		int total_sum = 0;
		int seper = 1;
		queue<pair<int, int>> q;
		memset(visited, 0, sizeof(visited));
		memset(check_map_sum, 0, sizeof(check_map_sum));
		memset(check_map_cnt, 0, sizeof(check_map_cnt));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int div_part = 0;
				if (visited[i][j] == 0) {
					//seper++; seper를 queue안에 추가해야할듯.
					q.push(make_pair(i, j));
					while (!q.empty()) {
						int c_y = q.front().first;
						int c_x = q.front().second;
						q.pop();
						for (int k = 0; k < 4; k++) {
							if (c_y + dy[k] < 0 || c_x + dx[k] < 0 || c_x + dx[k] >= N || c_y + dy[k] >= N)
								continue;
							int temp_v = abs(map[c_y][c_x] - map[c_y + dy[k]][c_x + dx[k]]);
							if (temp_v >= over && temp_v <= under) {							//해당 구역이 범위에 들어온 경우
								if (visited[c_y + dy[k]][c_x + dx[k]] == false) {
									div_part++;
									visited[c_y][c_x] = seper;
									visited[c_y + dy[k]][c_x + dx[k]] = seper;
									q.push(make_pair(c_y + dy[k], c_x + dx[k]));
								}
							}
						}
					}
					if (div_part > 0) {
						seper++;
					}
				}
				//seper++;
			}
		}
		for (int k = 1; k < seper; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (visited[i][j] != 0) {
						visit_count++;
						//total_sum += map[i][j];
					}
					if (visited[i][j] == k) {
						check_map_sum[k] += map[i][j];
						check_map_cnt[k]++;
					}
				}
			}
		}
		
		if (visit_count >= 2) {
			check = true;
			cnt++;
			//int div_value = total_sum / visit_count;
			for (int k = 1; k < seper; k++) {
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						if (visited[i][j] == k) {
							int temp_v = check_map_sum[k] / check_map_cnt[k];
							map[i][j] = temp_v;
						}
					}
				}
			}
			/*for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (visited[i][j] != 0) {
						map[i][j] = div_value;
					}
				}
			}*/
		}
	}

	cout << cnt << endl;

	return 0;
}
