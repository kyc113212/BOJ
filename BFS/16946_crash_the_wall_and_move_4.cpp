//16949 문제

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <cstring>

using namespace std;

int N, M;
int map_info[1001][1001];
int group[1000001];
int cnt_map[1001][1001];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int t_size = 0;
bool visited_group[1001];
int ans_map[1001][1001];

void dfs(int y, int x, int cnt) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= N || nx >= M || ny < 0 || nx < 0)
			continue;
		if (cnt_map[ny][nx])
			continue;
		if (map_info[ny][nx])
			continue;
		cnt_map[ny][nx] = cnt;
		t_size++;
		dfs(ny, nx, cnt);
	}
	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map_info[i][j] = s[j] - '0';
		}
	}

	int cnt = 0;
	int size = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cnt_map[i][j] == 0 && map_info[i][j] == 0) {
				t_size = 1;
				cnt++;
				cnt_map[i][j] = cnt;
				dfs(i, j, cnt);
				group[cnt] = t_size;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map_info[i][j] == 1) {
				map<int, bool> m;
				int ans = 1;
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny >= N || nx >= M || ny < 0 || nx < 0)
						continue;
					if (map_info[ny][nx])
						continue;
					if (m.count(cnt_map[ny][nx]))
						continue;
					m.insert({ cnt_map[ny][nx], true });
					ans += group[cnt_map[ny][nx]];
				}
				ans_map[i][j] = ans % 10;
			}			
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << ans_map[i][j];
		}
		cout << '\n';
	}




	return 0;
}
