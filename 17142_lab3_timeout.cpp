#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct pos {
	int x, y, cnt;
	pos(int a, int b, int c) : y(a), x(b), cnt(c) {}
};

int map[51][51];
int visited[51][51];
int visited_pos[51];
int N, v_cnt;
int total_cnt;
int ans;
int minV = 9999;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
//queue<pos> select_queue[11];



bool check_map(int arr[][51], int temp_visited[][51]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0 && temp_visited[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

int max_value(int arr[][51]) {
	int mv = -9999;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mv = max(mv, arr[i][j]);
		}
	}
	return mv;
}

void copy_map(int (*arr_1)[51], int (*arr_2)[51]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr_2[i][j] = arr_1[i][j];
		}
	}
}

int solve(vector<pos> tq[]) {
	queue<pos> temp_q[11];
	int k = 0;
	int ans = 0;
	int temp_map[51][51];
	int temp_visited[51][51];
	memset(temp_map, 0, sizeof(temp_map));
	memset(temp_visited, 0, sizeof(temp_visited));
	copy_map(map, temp_map);
	copy_map(visited, temp_visited);
	for (int i = 0; i < total_cnt; i++) {
		if (visited_pos[i] == true) {
			temp_q[k].push(tq[i][0]);
			temp_visited[tq[i][0].y][tq[i][0].x] = 1;
			k++;
		}
	}

	while (1) {
		
		bool flag = false;
		for (int i = 0; i < k; i++) {
			if (temp_q[i].empty() == false) {
				flag = true;
			}
		}
		if (flag == false && check_map(temp_map,temp_visited) == false) {
			return -1;
		}

		if (check_map(temp_map,temp_visited) == true) {
			if (ans == 0) {
				ans = 0;
			}
			else {
				ans = max_value(temp_visited);
			}
			return ans;
		}

		for (int i = 0; i < v_cnt; i++) {
			int c_size = temp_q[i].size();
			for (int j = 0; j < c_size; j++) {
				int cy = temp_q[i].front().y;
				int cx = temp_q[i].front().x;
				int c_cnt = temp_q[i].front().cnt;
				ans = max(c_cnt, ans);
				temp_q[i].pop();
				for (int k = 0; k < 4; k++) {
					int ny = cy + dy[k];
					int nx = cx + dx[k];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
						continue;
					if (temp_visited[ny][nx] == 0) {
						temp_visited[ny][nx] = 1;
						temp_map[ny][nx] = c_cnt + 1;
						temp_visited[ny][nx] = c_cnt + 1;
						temp_q[i].push(pos(ny, nx, c_cnt + 1));
					}
				}
			}
		}

		

	}

	return -1;
}

void select_pos(vector<pos> tq[], int v_size, int idx) {
	if (v_size == v_cnt) {
		ans = solve(tq);
		if (ans == -1) {
			if (minV == 9999 || minV == -1)
				minV = -1;
			return;
		}
		else {
			if (minV == -1) {
				minV = ans;
			}
			else {
				minV = min(ans, minV);
			}
			return;
		}
		return;
	}
	else {
		for (int i = idx; i < total_cnt; i++) {
			if (visited_pos[i] == false) {
				visited_pos[i] = true;
				select_pos(tq, v_size + 1, i);
				visited_pos[i] = false;
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> v_cnt;
	vector<pos> q[11];
	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				q[total_cnt].push_back(pos(i, j, 0));
				total_cnt++;
			}
			else if (map[i][j] == 1) {
				visited[i][j] = 1;
			}
		}
	}

	select_pos(q, 0, 0);
		

	cout << minV << endl;

	return 0;
}
