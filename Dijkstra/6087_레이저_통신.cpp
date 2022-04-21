#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct pos {
	int y, x, mirror_cnt, cur_dir;
	pos(int y, int x, int mc, int cd) : y(y), x(x), mirror_cnt(mc), cur_dir(cd) {}
};

struct cmp {
	bool operator ()(pos &a, pos &b) {
		return a.mirror_cnt > b.mirror_cnt;
	}
};

int map[101][101];
int visited[101][101];
int W, H;
vector<pair<int, int>> v;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

#define MAX 987654321

int bfs() {
	int s_x = v[0].second;
	int s_y = v[0].first;
	int e_x = v[1].second;
	int e_y = v[1].first;

	visited[s_y][s_x] = 0;

	priority_queue<pos, vector<pos>, cmp> pq;
	//queue<pos> pq;
	for (int i = 0; i < 4; i++) {
		pq.push(pos(s_y, s_x, 0, i));
	}

	while (!pq.empty()) {
		int cy = pq.top().y;
		int cx = pq.top().x;
		int cmc = pq.top().mirror_cnt;
		int c_dir = pq.top().cur_dir;
		pq.pop();

				
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int n_cmc = cmc;

			if (ny < 0 || nx < 0 || nx >= W || ny >= H)
				continue;
			if (map[ny][nx] == 1)
				continue;

			if (i != c_dir) {
				n_cmc = n_cmc + 1;
			}
			if (visited[ny][nx] >= n_cmc) {
				visited[ny][nx] = n_cmc;
				pq.push(pos(ny, nx, n_cmc, i));
			}
		}
	}

	return visited[e_y][e_x];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> W >> H;
	//memset(visited, -1, sizeof(visited));
	//fill(&visited[0][0], &visited[100][101], MAX);
	for (int i = 0; i < H; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < W; j++) {
			if (s[j] == '.') {
				map[i][j] = 0;
			}
			else if (s[j] == '*') {
				map[i][j] = 1; 
			}
			else if (s[j] == 'C') {
				v.push_back(make_pair(i, j));
			}
			visited[i][j] = MAX;
		}
	}

	cout << bfs() << '\n';

	return 0;
}
