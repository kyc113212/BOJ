#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>
#include <queue>

#define MAX_V 987654321
#define MOD_V 1000000007
#define T_MAX_V 1000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int N, M;
int map[21][21];
int group_cnt[401];
bool visited[21][21];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int ans = 0;
int maxV = 0;
int cnt = 0;
vector<pair<int, int>> group_pos[401];

int count_ai() {

	int cnt_dol = 0;
	for (int i = 1; i <= cnt; i++) {
		bool flag = false;
		for (int j = 0; j < group_pos[i].size(); j++) {
			int cy = group_pos[i][j].first;
			int cx = group_pos[i][j].second;
			
			for (int k = 0; k < 4; k++) {
				int ny = cy + dy[k];
				int nx = cx + dx[k];
				if (ny < 0 || nx < 0 || nx >= M || ny >= N)
					continue;
				if (map[ny][nx] == 0) {
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		if (!flag) {
			cnt_dol += group_cnt[i];
		}
	}

	return cnt_dol;
}

void grouping(int y, int x, int cnt) {
	visited[y][x] = true;
	ans++;
	group_pos[cnt].push_back(make_pair(y, x));
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || nx >= M || ny >= N)
			continue;
		if (visited[ny][nx])
			continue;
		if (map[ny][nx] == 2) {
			grouping(ny, nx, cnt);
		}
	}
}

void select_dot(int y, int x, int cnt) {
	if (cnt == 1) {
		maxV = max(count_ai(), maxV);
		return;
	}
	for (int i = y; i < N; i++) {
		for (int j = x; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				select_dot(i, j + 1, cnt+1);
				map[i][j] = 0;
			}
		}
		x = 0;
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2 && visited[i][j] == false) {
				cnt++;
				ans = 0;
				grouping(i, j, cnt);
				group_cnt[cnt] = ans;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				select_dot(i, j + 1, 0);
				map[i][j] = 0;
			}
		}
	}

	cout << maxV << '\n';
	
	return 0;
}
