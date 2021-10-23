#include <iostream>
#include <cstring>

using namespace std;

long long N, M;
long long map[501][501];
long long dp[501][501];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int dfs(int y, int x) {

	if (y == N - 1 && x == M - 1) {
		return 1;
	}
	else if(dp[y][x] == -1) {
		dp[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			if (map[ny][nx] >= map[y][x])
				continue;
			dp[y][x] += dfs(ny, nx);
		}
	}

	return dp[y][x];
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0) << '\n';

	int a = 0;
	//cout << ans << endl;

	return 0;
}
