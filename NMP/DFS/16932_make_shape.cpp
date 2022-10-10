// 16932
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
#define PIE 3.14159265358979323846
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int map[1001][1001];
int group_map[1001][1001];
int group_size[1000001];
int maxV = 1;
int N, M;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int group_cnt = 0;
int g_size = 0;

void make_group(int y, int x) {
	group_map[y][x] = group_cnt;
	g_size++;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			continue;
		if (group_map[ny][nx] != 0)
			continue;
		if (map[ny][nx] == 0)
			continue;
		make_group(ny, nx);
	}
}

void solve(int y, int x) {
	int ans = 1;
	vector<int> visit_check;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			continue;
		if (group_map[ny][nx] == 0)
			continue;
		bool flag = true;
		for (int j = 0; j < visit_check.size(); j++) {
			if (group_map[ny][nx] == visit_check[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			visit_check.push_back(group_map[ny][nx]);
			ans += group_size[group_map[ny][nx]];
		}
	}
	maxV = max(maxV, ans);
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
	// 모두 1인경우 0을 하나 뺀 것이 최대값?

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && group_map[i][j] == 0) {
				group_cnt++;
				g_size = 0;
				make_group(i, j);
				group_size[group_cnt] = g_size;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				solve(i, j);
			}
		}
	}

	cout << maxV << '\n';


	return 0;
}
