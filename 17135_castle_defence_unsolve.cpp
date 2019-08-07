#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int map[16][15];
int N, M, D;
int select[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
int visited[15];
vector<int> v;
int maxV = -9999;
int dx[] = { -1,1,0 };
int dy[] = { 0,0,-1 };

int temp_y[] = { 0,0,0,-1 };

struct pos {
	int x, y, cnt;
	pos(int a, int b, int c) : y(a), x(b), cnt(c) {}
};

bool check_map(int arr[][15]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != 0)
				return false;
		}
	}
	return true;
}

void rearrange_map(int (*arr2)[15]) {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			/*if (arr2[i+1][j] == 1) {
				arr2[i + 1][j] = arr2[i][j];
				//arr[]
			}*/
			arr2[i][j] = arr2[i - 1][j];
		}
	}
	for (int j = 0; j < M; j++) {
		arr2[0][j] = 0;
	}
}

void copymap(int (*arr1)[15], int (*arr2)[15]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr1[i][j] = arr2[i][j];
		}
	}
}

int solve(vector<int> &v) {
	
	int temp_map[16][15];
	memset(temp_map, 0, sizeof(temp_map));
	queue<pos> q;
	copymap(temp_map, map);
	for (int i = 0; i < 3; i++) {
		temp_map[N][v[i]] = 1;
		q.push(pos(N, v[i], 0));
	}

	int cnt = 0;

	int q_size = q.size();
	/*for (int j = 0; j < q_size; j++) {
		int cx = q.front().x;
		int cy = q.front().y;
		int c_cnt = q.front().cnt;
		q.pop();
		int nx = cx + temp_y[3];
		int ny = cy + temp_y[3];
		int n_cnt = c_cnt + 1;
		if (temp_map[ny][nx] == 1) {
			cnt++;
			temp_map[ny][nx] = 0;
			q.push(pos(ny, nx, c_cnt + 1));
		}
	}*/

	while (check_map(temp_map) == false) {
		//int count = 0;
		while (1) {
			if (q.empty() == true) {
				break;
			}
			while (q.front().cnt < D) {
				int cx = q.front().x;
				int cy = q.front().y;
				int c_cnt = q.front().cnt;
				q.pop();
				if (c_cnt == 0) {
					int nx = cx;
					int ny = cy + temp_y[3];
					int n_cnt = c_cnt + 1;
					if (nx >= M && ny >= N && nx < 0 && ny < 0)
						continue;
					if (temp_map[ny][nx] == 1) {
						cnt++;
						temp_map[ny][nx] = 0;
						//q.push(pos(ny, nx, cnt + 1));
					}
					else {
						q.push(pos(ny, nx, cnt + 1));
					}
				}
				else {
					for (int i = 0; i < 3; i++) {
						int nx = cx + dx[i];
						int ny = cy + dy[i];
						int n_cnt = c_cnt + 1;
						if (nx >= M && ny >= N && nx < 0 && ny < 0)
							continue;
						if (temp_map[ny][nx] == 1) {
							cnt++;
							temp_map[ny][nx] = 0;
							//q.push(pos(ny, nx, cnt + 1));
						}
						else {
							q.push(pos(ny, nx, cnt + 1));
						}
					}
				}
			}
		}
		

		while (!q.empty()) {
			q.pop();
		}

		rearrange_map(temp_map);
		/*for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M; j++) {
				if (temp_map[i][j] == 1) {
					temp_map[i + 1][j] = temp_map[i][j];
				}
			}
		}*/
		for (int i = 0; i < 3; i++) {
			temp_map[N][v[i]] = 1;
			q.push(pos(N, v[i], 0));
		}

	}

	return cnt;
}

void select_pos(int cnt, int idx) {
	if (cnt == 3) {
		int ans = solve(v);
		maxV = max(maxV, ans);
		return;
	}
	for (int i = idx; i < M; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			v.push_back(i);
			select_pos(cnt + 1, i+1);
			visited[i] = 0;
			v.pop_back();
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

	select_pos(0, 0);

	cout << maxV << endl;

	return 0;
}
