// 17069
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
int map[16][16];
int check_map[16][16];
int ans = 1;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int max_V = 0;

bool check_cross(int y, int x, int size) {
	if (y - size < 0 || x - size < 0 || y + size >= N || x + size >= M) {
		return false;
	}
	for (int i = y - size; i <= y + size; i++) {
		if (map[i][x] == 0)
			return false;
	}
	for (int i = x - size; i <= x + size; i++) {
		if (map[y][i] == 0)
			return false;
	}

	return true;
}

void clear_map(int y, int x, int size) {
	for (int i = y - size; i <= y + size; i++) {
		if (map[i][x] == 1)
			map[i][x] = 0;
	}
	for (int i = x - size; i <= x + size; i++) {
		if (map[y][i] == 1)
			map[y][i] = 0;
	}
}

void input_map(int y, int x, int size) {
	for (int i = y - size; i <= y + size; i++) {
		map[i][x] = 1;
	}
	for (int i = x - size; i <= x + size; i++) {
		map[y][i] = 1;	}
}



int find_size(int range, int y, int x) {

	for (int i = range; i >= 1; i--) {
		if (y - i < 1 || x - i < 1 || y + i > N || x + i > M) {
			continue;
		}
		if (check_cross(y, x, i)) {
			clear_map(y, x, i);
			return i;
			// clear map도 해주고
			// return size
		}
	}

	return 0;
}

void dfs(int y, int x, int ans, int cnt) {
	if (cnt == 2) {
		max_V = max(ans, max_V);
		return;
	}

	for (int i = y; i < N; i++) {
		for (int j = x; j < M; j++) {
			if (map[i][j] == 1) {
				for (int k = min(N, M) / 2; k >= 0; k--) {
					if (check_cross(i, j, k)) {
						clear_map(i, j, k);
						int area = 4 * k + 1;
						//max_V = max(max_V, area);
						dfs(i, j, ans * area, cnt + 1);
						input_map(i, j, k);
					}
				}
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
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '#') {
				map[i][j] = 1;
			}
		}
	}

	dfs(0, 0, 1, 0);
	cout << max_V << '\n';

	return 0;
}
