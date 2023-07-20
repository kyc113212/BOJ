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

int N, M, H;
int map[31][12];
int minV = MAX_V;

bool move_bridge() {
	bool check = true;
	for (int i = 1; i <= N; i++) {
		int cur_line = i;
		for (int j = 1; j <= H; j++) {
			if (map[j][cur_line] == 0 && map[j][cur_line-1] == 0)
				continue;
			if (map[j][cur_line] == 1) {
				cur_line++;
			}
			else if (map[j][cur_line - 1] == 1) {
				cur_line--;
			}
		}
		if (cur_line == i) {
			continue;
		}
		else
			return false;
	}

	return true;
}

void select_bridge(int r, int c, int cnt) {
	if (cnt > 3)
		return;
	// 올때마다 정상적으로 내려가는지 확인
	if (map[5][4] == 1 && map[6][2] == 1)
		int ans = 0;
	if (move_bridge()) {
		minV = min(cnt, minV);
	}

	// 세개 이상이면 걍 return;
	if (cnt == 3)
		return;

	for (int i = r; i <= H; i++) {
		for (int j = c; j < N; j++) {
			if (map[i][j] == 0 && map[i][j - 1] == 0 && map[i][j + 1] == 0) {
				map[i][j] = 1;
				select_bridge(i, j + 1, cnt + 1);
				map[i][j] = 0;
			}
		}
		c = 0;
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}

	if (move_bridge()) {
		minV = min(0, minV);
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (map[i][j] == 0 && map[i][j-1] == 0 && map[i][j+1] == 0) {
				map[i][j] = 1;
				select_bridge(i, j + 1, 1);
				map[i][j] = 0;
			}
		}
	}

	if (minV == MAX_V) {
		cout << -1 << '\n';
	}
	else
		cout << minV << '\n';
	
	return 0;
}
