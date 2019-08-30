#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct pos {
	int y, x;
	int range;
	pos(int a, int b, int c) : y(a), x(b), range(c) {}
};

int maxV = 0;
int map[51][51];
int visited[6];
int R, C, K;
vector<pos> v;

void copy_map(int origin[][51], int copy[][51]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < R; j++) {
			copy[i][j] = origin[i][j];
		}
	}
}

void calc_value(int arr[][51]) {

	int sum = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			sum += arr[i][j];
		}
		maxV = max(sum, maxV);
		sum = 0;
	}

}

void solve(vector<pos> &tv) {

	int temp_map[51][51];
	memset(temp_map, 0, sizeof(temp_map));
	copy_map(map, temp_map);

	for (int i = 0; i < tv.size(); i++) {
		int c_x = tv[i].x;
		int c_y = tv[i].y;
		int c_range = tv[i].range;

		for (int r = 1; r <= c_range; r++) {
			int s_x = c_x - r;
			int s_y = c_y - r;
			int e_x = c_x + r;
			int e_y = c_y + r;
			int around = r * 8;
			int i = 0;
			


		}
	}

	calc_value(temp_map);
	
}

void dfs(int idx, int select_count, vector<pos> &tv) {
	if (select_count == K) {
		solve(tv);
		//maxV = max(ans, maxV);
		return;
	}

	for (int i = 0; i < K; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			tv.push_back(v[i]);
			dfs(i, select_count + 1,tv);
			tv.pop_back();
			visited[i] = false;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> K;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int y, x, range;
		cin >> y >> x >> range;
		v.push_back(pos(y - 1, x - 1, range));
	}

	vector<pos> temp_v;

	for (int i = 0; i < K; i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp_v.push_back(v[i]);
			dfs(i, 1, temp_v);
			temp_v.pop_back();
			visited[i] = false;
		}
	}

	return 0;
}
