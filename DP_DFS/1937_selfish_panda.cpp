#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[501][501];
int DP[501][501];

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int N;
int maxV = 1;

int dfs(int y, int x) {
	if (DP[y][x] != 0) {
		return DP[y][x];
	}
	else {
		DP[y][x] = 1;
	}

	int rst = DP[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < N && ny >= 0 && nx < N && nx >= 0) {
			if (arr[ny][nx] > arr[y][x]) {
				rst += dfs(ny, nx);
				DP[y][x] = max(DP[y][x], rst);
				rst = 1;
				maxV = max(DP[y][x], maxV);
			}
		}
	}

	return DP[y][x];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dfs(i, j);
		}
	}

	cout << maxV << endl;


	return 0;
}
