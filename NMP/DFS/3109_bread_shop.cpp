#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int map[10001][501];
int visited[10001][501];
int dy[] = { -1,0,1 };
int dx[] = { 1,1,1 };
int R, C;
int ans = 0;

bool dfs(int y, int x) {
	if (x == C - 1) {
		ans++;
		return true;
	}

	for (int i = 0; i < 3; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= R || ny < 0)
			continue;
		if (map[ny][nx] == 1)
			continue;
		if (visited[ny][nx])
			continue;
		visited[ny][nx] = 1;
		if (dfs(ny, nx)) {
			return true;
		}	
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			if (s[j] == '.') {
				map[i][j] = 0;
			}
			else
				map[i][j] = 1;
		}
	}

	for (int i = 0; i < R; i++) {
		visited[i][0] = 1;
		dfs(i, 0);
	}

	cout << ans << '\n';

	return 0;
}
