#include <iostream>
#include <queue>

using namespace std;

int row, col;
int s_x, s_y, s_dir;
int map[51][51];
int visited[51][51];

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0, 1,0 };

int rdx[] = { 0,-1,0,1 };
int rdy[] = { 1,0,-1,0 };

struct pos {
	int y, x, dir, cnt;
	pos(int a, int b, int c, int d) : y(a), x(b), dir(c), cnt(d) {}
};

bool check_dir(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];
		if (map[next_y][next_x] == 0 && visited[next_y][next_x] == 0)
			return false;
	}

	return true; //true인 경우 다 막혀 있다는 것
}

int bfs(queue<pos>& q) {

	q.push(pos(s_y, s_x, s_dir, 1));
	visited[s_y][s_x] = true;
	int f_cnt = 0;

	while (!q.empty()) {
		int cur_y = q.front().y;
		int cur_x = q.front().x;
		int cur_dir = q.front().dir;
		int cur_cnt = q.front().cnt;
		f_cnt = cur_cnt;
		q.pop();

		int next_dir = cur_dir - 1;
		if (next_dir < 0)
			next_dir = 3;

		int next_y = cur_y;
		int next_x = cur_x;

		while (1) {

			next_y = cur_y + dy[next_dir];
			next_x = cur_x + dx[next_dir];

			if (map[next_y][next_x] == 0 && visited[next_y][next_x] == 0) {
				visited[next_y][next_x] = 1;
				q.push(pos(next_y, next_x, next_dir, cur_cnt + 1));
				break;
			}
			else if (map[next_y][next_x] == 1 || visited[next_y][next_x] == 1) {				
				if (cur_dir == next_dir) {
					if (map[cur_y + rdy[cur_dir]][cur_x + rdx[cur_dir]] == 1) {
						return cur_cnt;
					}
					else {
						q.push(pos(cur_y + rdy[cur_dir], cur_x + rdx[cur_dir], next_dir, cur_cnt));
						break;
					}
				}
				next_dir--;
				if (next_dir < 0)
					next_dir = 3;
			}
		}
	}

	return f_cnt;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<pos> q;

	cin >> row >> col;
	cin >> s_y >> s_x >> s_dir;


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}

	int ans = bfs(q);

	cout << ans << endl;

	return 0;
}
