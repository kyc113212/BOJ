#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>

#define MAX_V 1000000001
using namespace std;
typedef long long ll;
int dy[] = { 1,0,0,0,-1,-1,-1 };
int dx[] = { 1,-1,0,1,-1,0,1 };


struct info {
	int y, x;
	bool alive;
	info(int y, int x, bool a) : y(y), x(x), alive(a) {}
};

int map[8][8];

bool bfs() {

	deque<info> dq;
	//이동 하고 내려오고
	dq.push_back(info(7, 0, true));

	while (!dq.empty()) {
		int dq_size = dq.size();
		for (int i = 0; i < dq_size; i++) {
			int cy = dq.front().y;
			int cx = dq.front().x;
			bool calive = dq.front().alive;
			dq.pop_front();
			if (!calive)
				continue;
			if (cy == 0 && cx == 7)
				return true;
			for (int j = 0; j < 7; j++) {
				int ny = cy + dy[j];
				int nx = cx + dx[j];
				if (ny < 0 || nx < 0 || ny > 7 || nx > 7)
					continue;
				if (map[ny][nx])
					continue;
				dq.push_back(info(ny, nx, true));
			}
		}
		// 벽돌 아래로 움직임
		vector<info> wall;
		for (int i = 7; i >= 0; i--) {
			for (int j = 0; j < 8; j++) {
				if (map[i][j] == 1) {
					int ny = i + 1;
					if (ny < 0)
						continue;
					map[i][j] = 0;
					map[ny][j] = 1;
					wall.push_back(info(ny, j, true));
				}
			}
		}
		for (int i = 0; i < dq.size(); i++) {
			for (int j = 0; j < wall.size(); j++) {
				if (dq[i].y == wall[j].y && dq[i].x == wall[j].x) {
					dq[i].alive = false;
				}
			}
		}
	}

	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 8; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++) {
			if (s[j] == '#') {
				map[i][j] = 1;
			}
		}
	}

	if (bfs()) {
		cout << 1 << '\n';
	}
	else {
		cout << 0 << '\n';
	}
	

	return 0;
}
