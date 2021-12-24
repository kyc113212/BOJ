
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
char map[251][251];
int visited[251][251];
int cnt_map[251][251];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

struct pos {
	int y, x, cnt;
	pos(int a, int b) : y(a), x(b) {}
};

void dfs(int y, int x, int num) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			continue;
		if (map[ny][nx] == '#')
			continue;
		if (visited[ny][nx])
			continue;
		visited[ny][nx] = 1;
		cnt_map[ny][nx] = num;
		dfs(ny, nx, num);
	}
}

int main() {

	cin >> N >> M;
	vector<pos> sheep, wolf;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'k')
				sheep.push_back(pos(i, j));
			if (map[i][j] == 'v')
				wolf.push_back(pos(i, j));
		}
	}

	int area_number = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != '#' && visited[i][j] == 0) {
				visited[i][j] = 1;
				cnt_map[i][j] = area_number;
				dfs(i, j, area_number);
				area_number++;
			}
		}
	}

	//int a = 0;
	vector<pair<int,int>> cmp;
	cmp.resize(area_number+1);

	for (int i = 0; i < sheep.size(); i++) {
		cmp[cnt_map[sheep[i].y][sheep[i].x]].first++;	//first가 양 second가 늑대
	}
	for (int i = 0; i < wolf.size(); i++) {
		cmp[cnt_map[wolf[i].y][wolf[i].x]].second++;
	}

	int s_cnt = 0;
	int w_cnt = 0;
	for (int i = 0; i < cmp.size(); i++) {
		if (cmp[i].first > cmp[i].second) {
			s_cnt += cmp[i].first;
		}
		else
			w_cnt += cmp[i].second;
	}

	cout << s_cnt << " " << w_cnt << '\n';

	return 0;
}
