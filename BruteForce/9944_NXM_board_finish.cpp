//16917

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

int map[31][31];
int R, C;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int min_cnt = MAX_V;

bool all_visit() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 0)
				return false;
		}
	}
	return true;
}


void dfs(int y, int x, int cnt) {
	if (all_visit()) {
		min_cnt = min(cnt, min_cnt);
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= R || nx >= C) {
			continue;
		}
		if (map[ny][nx])
			continue;
		int nny = y;
		int nnx = x;
		while (1) {
			map[nny][nnx] = 1;
			nny += dy[i];
			nnx += dx[i];
			if (nny < 0 || nnx < 0 || nny >= R || nnx >= C) {
				break;
			}
			if (map[nny][nnx] == 1)
				break;
		}
		dfs(nny - dy[i], nnx - dx[i], cnt + 1);
		// map 원상 복구
		while (1) {
			nny -= dy[i];
			nnx -= dx[i];
			map[nny][nnx] = 0;
			if (nny == y && nnx == x)
				break;
		}
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int case_n = 1;
	while (cin >> R >> C) {
		memset(map, 0, sizeof(map)); 
		min_cnt = MAX_V;
		for(int i = 0; i < R; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < s.size(); j++) {
				if (s[j] == '*') {
					map[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] == 1)
					continue;
				map[i][j] = 1;
				dfs(i, j, 0);
				map[i][j] = 0;
			}
		}
		if (min_cnt == MAX_V) {
			cout << "Case " << case_n << ": " << -1 << '\n';
		}
		else
			cout << "Case " << case_n << ": " << min_cnt << '\n';
		case_n++;
	}

	return 0;
}
