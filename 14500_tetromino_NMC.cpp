#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[501][501];
int visited[51][51];
int N, M;
int ans = -9999;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void solve() {
	//ㅜ
	int temp_v = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			temp_v = map[i][j] + map[i][j - 1] + map[i][j + 1] + map[i + 1][j];
			ans = max(temp_v, ans);
		}
	}
	//ㅏ
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			temp_v = map[i][j] + map[i+1][j] + map[i][j + 1] + map[i - 1][j];
			ans = max(temp_v, ans);
		}
	}
	//ㅗ
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			temp_v = map[i][j-1] + map[i][j] + map[i][j + 1] + map[i - 1][j];
			ans = max(temp_v, ans);
		}
	}
	//ㅓ
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			temp_v = map[i][j - 1] + map[i][j] + map[i + 1][j] + map[i - 1][j];
			ans = max(temp_v, ans);
		}
	}
}

void dfs(int y, int x, int cnt, int sum) {
	if (cnt == 4) {
		ans = max(ans, sum);
	}
	else {
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny < N && nx < M && nx >= 0 && ny >= 0 && !visited[ny][nx]) {
				visited[ny][nx] = 1;
				dfs(ny, nx, cnt + 1, map[ny][nx] + sum);
				visited[ny][nx] = 0;
			}
		}
	}
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 1;
			dfs(i, j, 1, map[i][j]);
			visited[i][j] = 0;
		}
	}

	solve();

	cout << ans << endl;

	return 0;

}
