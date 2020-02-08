#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct pos {
	int y, x, cnt, start_idx;
	pos(int a, int b, int c, int d) : y(a), x(b), cnt(c), start_idx(d) {}
};

int map[15][15];
int check_archor[15];
int N, M, D;
int dx[] = { -1,0,1 };
int dy[] = { 0,-1,0 };
int maxV = 0;

bool check_all(int temp_map[][15]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp_map[i][j] != 0)
				return false;
		}
	}

	return true;
}

int solve(vector<int> &tv) {
	int a;
	int temp_map[15][15];
	int check_visited[15][15];
	int check_final[15];
	memset(temp_map, 0, sizeof(temp_map));
	memset(check_visited, 0, sizeof(check_visited));
	memset(check_final, 0, sizeof(check_final));

	int count_kill = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp_map[i][j] = map[i][j];
		}
	}

	while (!check_all(temp_map)) {
		queue<pos> q;

		memset(check_final, 0, sizeof(check_final));
		queue<pos> temp_q;
		for (int i = 0; i < tv.size(); i++) {
			memset(check_visited, 0, sizeof(check_visited));
			//memset(check_final, 0, sizeof(check_final));
			q.push(pos(N, tv[i], 0, i));	//y,x,cnt,idx
			while (!q.empty()) {
				int cx = q.front().x;
				int cy = q.front().y;
				int c_cnt = q.front().cnt + 1;
				//int c_idx = q.front().start_idx + 1;
				q.pop();
				for (int j = 0; j < 3; j++) {
					int nx = cx + dx[j];
					int ny = cy + dy[j];
					if (nx < 0 || ny < 0 || nx >= M || ny >= N)
						continue;
					if (check_visited[ny][nx] == 1)
						continue;
					/*if (c_cnt == D) {
						if (check_final[c_idx] == 0) {
							if (temp_map[ny][nx] == 1) {
								count_kill++;
								temp_map[ny][nx] = 0;
								check_final[c_idx] = 1;
							}
						}
					}*/
					//우선순위가 높은 적부터 죽여야됨
					if (c_cnt <= D) {
						if (check_final[i] == 0) {
							if (temp_map[ny][nx] == 1 || temp_map[ny][nx] == 2) {//check_final[c_idx] == 0
								if (temp_map[ny][nx] == 1) {
									count_kill++;
									temp_map[ny][nx] = 2;
									temp_q.push(pos(ny, nx, 0, 0));
									check_final[i] = 1;
								}
								else {
									temp_map[ny][nx] = 2;
									temp_q.push(pos(ny, nx, 0, 0));
									check_final[i] = 1;
								}
								//break;
							}
							else {
								check_visited[ny][nx] = 1;
								q.push(pos(ny, nx, c_cnt, i));
							}
						}
						
					}
				}
			}

		}

		//한턴 끝난 이후 0으로
		while (!temp_q.empty()) {
			int cx = temp_q.front().x;
			int cy = temp_q.front().y;
			temp_map[cy][cx] = 0;
			temp_q.pop();
		}
		
		for (int i = 0; i < M; i++) {
			int temp_y_v = temp_map[0][i];
			int temp_y_v2 = temp_map[1][i];
			int j = 1;
			while (j < N) {
				temp_map[j][i] = temp_y_v;
				temp_y_v = temp_y_v2;
				j++;
				temp_y_v2 = temp_map[j][i];
			}
		}
		for (int i = 0; i < M; i++) {
			temp_map[0][i] = 0;
		}

		
	}

	//cout << count_kill << endl;

	return count_kill;
}

void dfs(vector<int> &tv, int cnt,int idx) {
	if (cnt == 3) {
		maxV = max(maxV,solve(tv));
		return;
	}
	for (int i = idx; i < M; i++) {
		if (check_archor[i] == 0) {
			check_archor[i] = 1;
			tv.push_back(i);
			dfs(tv, cnt + 1, i + 1);
			check_archor[i] = 0;
			tv.pop_back();
		}
	}
}

int main() {

	cin >> N >> M >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	vector<int> tv;
	for (int i = 0; i < N; i++) {
		check_archor[i] = 1;
		tv.push_back(i);
		dfs(tv, 1, i);
		check_archor[i] = 0;
		tv.pop_back();
	}

	cout << maxV << endl;


	return 0;
}
