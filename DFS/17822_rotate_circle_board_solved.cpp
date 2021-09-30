#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct info {
	int xi, di, ki;
	info(int a, int b, int c) : xi(a), di(b), ki(c) {}
};

int N, M, T;
int map[52][52];
int visited[52][52];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void do_rotate(int row_idx, int dir, int cnt) {
	if (dir == 0) {//시계
		for (int j = 0; j < cnt; j++) {
			int temp1 = map[row_idx][1];
			int temp2 = map[row_idx][2];
			int final_value = map[row_idx][M];
			int i = 2;
			while (i <= M) {
				map[row_idx][i] = temp1;
				temp1 = temp2;
				i++;
				temp2 = map[row_idx][i];
			}
			map[row_idx][1] = final_value;
		}
	}
	else if (dir == 1) { //반시계
		for (int j = 0; j < cnt; j++) {
			int temp1 = map[row_idx][M];
			int temp2 = map[row_idx][M-1];
			int first_value = map[row_idx][1];
			int i = M - 1;
			while (i >= 1) {
				map[row_idx][i] = temp1;
				temp1 = temp2;
				i--;
				temp2 = map[row_idx][i];
			}
			map[row_idx][M] = first_value;
		}
	}
}

void dfs(int cur_value, int y, int x) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (ny == 0 || ny == N + 1)
			continue;
		if (nx == M + 1)
			nx = 1;
		/*if (ny == N + 1)
			ny = 1;*/
		if (nx == 0)
			nx = M;
		/*if (ny == -1)
			ny = N;*/
		if (map[ny][nx] == cur_value && visited[ny][nx] == 0) {
			visited[ny][nx] = 1;
			dfs(cur_value, ny, nx);
			map[ny][nx] = 0;
		}
	}

}

int main() {

	cin >> N >> M >> T;
	vector<info> v;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < T; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		v.push_back(info(x, d, k));
	}

	for (int tc = 0; tc < v.size(); tc++) {
		int cx = v[tc].xi;
		int cd = v[tc].di;
		int ck = v[tc].ki;
		for (int i = 1; i <= N; i++) {
			if (i % cx == 0) {
				do_rotate(i, cd, ck);
			}
		}


		bool final_check = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				memset(visited, 0, sizeof(visited));				
				if (map[i][j] != 0) {
					//해당 값이 0이 아닌경우
					//먼저 주변에 같은 값이 있는지 확인
					//있는경우 visitied 표시하고, dfs진입
					//계속 visited 표시하고 visited 표시되어 있는 위치 0으로 reset
					bool check_around = false;
					int c_value = map[i][j];
					for (int k = 0; k < 4; k++) {
						int nx = j + dx[k];
						int ny = i + dy[k];
						if (ny == 0 || ny == N + 1)
							continue;
						if (nx == M + 1)
							nx = 1;
						/*if (ny == N + 1)
							ny = 1;*/
						if (nx == 0)
							nx = M;
						/*if (ny == -1)
							ny = N;*/
						if (map[ny][nx] == c_value) {
							check_around = true;
							final_check = true;
						}
					}
					if (check_around == true) {
						visited[i][j] = 1;
						dfs(c_value,i,j);
						map[i][j] = 0;
					}
				}


			}
		}

		if (final_check == false) {		//아무도 이동한게 없는경우
			double avg_value = 0;
			int sum_value = 0;
			int value_cnt = 0;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					sum_value += map[i][j];
					if (map[i][j] != 0)
						value_cnt++;
				}
			}
			avg_value = (double)sum_value / (double)value_cnt;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (map[i][j] != 0) {
						if (avg_value < map[i][j]) {
							map[i][j] = map[i][j] - 1;
						}
						else if (avg_value > map[i][j])
							map[i][j] = map[i][j] + 1;
					}
				}
			}
		}
	}

	int sumV = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			sumV += map[i][j];
		}
	}

	cout << sumV << endl;

	return 0;
}
