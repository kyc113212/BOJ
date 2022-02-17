#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int map[51][51];
bool visited[51][51];
int cnt_map[51][51];
int size_map[51][51];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int N, M;
int room_cnt = 0;
vector<int> room_size; 
//정렬후 뒤에것 더하면 됨
//방이 하나인 경우도 고려

void dfs(int y, int x, int room_cnt) {

	visited[y][x] = true;
	cnt_map[y][x] = room_cnt;
	room_size[room_cnt]++;
	for (int i = 0; i < 4; i++) {
		int status = map[y][x];
		int ny = y;
		int nx = x;
		if (!(status & (1 << i))) {
			if (i == 0) { //서
				nx--;
			}
			else if (i == 1) { // 북
				ny--;
			}
			else if (i == 2) { // 동
				nx++;
			}
			else { //남
				ny++;
			}
		}
		if (ny < 0 || nx < 0 || nx >= M || ny >= N)
			continue;
		if (visited[ny][nx])
			continue;
		dfs(ny, nx, room_cnt);
	}
	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cnt_map, -1, sizeof(cnt_map));
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == false) {
				room_size.push_back(0);
				dfs(i, j, room_cnt);
				room_cnt++;
			}
		}
	}

	for (int k = 0; k < room_size.size(); k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (cnt_map[i][j] == k) {
					size_map[i][j] = room_size[k];
				}
			}
		}
	}

	int ans_room_cnt = room_size.size();
	int ans_large_room = 0;
	int ans_minus_wall = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || nx >= M || ny >= N)
					continue;
				if(cnt_map[i][j] != cnt_map[ny][nx])
					ans_minus_wall = max(ans_minus_wall, size_map[i][j] + size_map[ny][nx]);
			}
		}
	}
	sort(room_size.begin(), room_size.end());
	ans_large_room = room_size[room_size.size() - 1];

	cout << ans_room_cnt << '\n';
	cout << ans_large_room << '\n';
	cout << ans_minus_wall << '\n';

	return 0;
}
