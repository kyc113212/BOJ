#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct pos {
	int y, x, size, dist;
	pos(int a, int b, int c, int d) : y(a), x(b), size(c), dist(d) {}
};

struct f_info {
	int y, x, size;
	bool alive;
	f_info(int a, int b, int c, bool d) : y(a), x(b), size(c), alive(d) {}
};

#define MAX_V 987654321

vector<pos> shark;
vector<f_info> fish;
int map[21][21];
int ans = 0;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int N;
int eat_cnt = 0;

bool fish_sort(f_info& a, f_info& b) {
	return a.size < b.size;
}

bool dist_sort(pos& a, pos& b) {
	return a.dist < b.dist;
}

bool idx_sort(pos& a, pos& b) {
	return a.size < b.size;
}

bool pro_sort(pos& a, pos& b) {
	if (a.y == b.y)
		return a.x < b.x;
	else
		return a.y < b.y;
}

int bfs(int s_y, int s_x, int t_y, int t_x, int cur_size) {
	int dist = 0;
	queue<pos> q;
	q.push(pos(s_y, s_x, 0, 0));
	int visited[21][21];
	memset(visited, 0, sizeof(visited));

	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		int c_dist = q.front().dist;
		q.pop();
		if (visited[cy][cx])
			continue;
		visited[cy][cx] = 1;
		if (cy == t_y && cx == t_x) {
			return c_dist;
		}
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if(visited[ny][nx])
				continue;
			if(map[ny][nx] <= cur_size || map[ny][nx] == 9)
			q.push(pos(ny, nx, 0, c_dist + 1));

		}
	}

	return -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	for(int i = 0; i<N; i++){
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark.push_back(pos(i, j, 2, 0));
			}
			else if (map[i][j] != 0) {
				fish.push_back(f_info(i, j, map[i][j], true));
			}
		}
	}

	//sort(fish.begin(), fish.end(), fish_sort);

	// 자기보다 작은 물고기 모아두기 & 도달할 수 있는지 확인
	// 같은 거리인 경우 위에있는지 - 1순위, 왼쪽에 있는지 확인 - 2순위
	// 도달할 수 있으면

	while (1) {
		// 자기보다 작은 물고기 모아두기 -> 안됨
		// 자기가 먹을 수 있는 물고기 중 가장 가까운 거리중 우선순위가 가장 높은 것 찾기
		int temp_map[21][21];
		memset(temp_map, -1, sizeof(temp_map));
		vector<pos> tv;
		for (int i = 0; i < fish.size(); i++) {
			if (map[fish[i].y][fish[i].x] != 0 && map[fish[i].y][fish[i].x] != 9 && shark[0].size > fish[i].size)
				tv.push_back(pos(fish[i].y, fish[i].x, fish[i].size, 0));
		}
		for (int i = 0; i < tv.size(); i++) {
			tv[i].dist = bfs(shark[0].y, shark[0].x, tv[i].y, tv[i].x, shark[0].size);
			if (tv[i].dist != -1) {
				temp_map[tv[i].y][tv[i].x] = tv[i].dist;
			}
		}

		int min_dist = MAX_V;
		int check_y = -1;
		int check_x = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (temp_map[i][j] != -1) {
					if (min_dist > temp_map[i][j]) {
						check_y = i;
						check_x = j;
						min_dist = temp_map[i][j];
					}
				}
			}
		}

		if (min_dist == MAX_V) {
			break;
		}
		else {
			map[check_y][check_x] = 9;
			map[shark[0].y][shark[0].x] = 0;
			shark[0].y = check_y;
			shark[0].x = check_x;
			// ans에 이동한 거리 추가
			// 자기 size만큼 먹었으면 size 증가
			ans += min_dist;
			eat_cnt++;
			if (eat_cnt == shark[0].size) {
				eat_cnt = 0;
				shark[0].size++;
			}
		}

	}

	cout << ans << '\n';

	return 0;
}
