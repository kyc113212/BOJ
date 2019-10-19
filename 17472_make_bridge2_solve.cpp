#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int map[11][11];
int graph[11][11];
int visited_labeling[11][11];
int labeling[11][11];
int vertex_dist[11];
int visited_vertex[11];

struct pos {
	int next_vertex, next_cost;
	pos(int a, int b) : next_vertex(a), next_cost(b) {}
};

struct cmp {
	bool operator() (pos a, pos b) {
		return a.next_cost > b.next_cost;
	}
};

void labeling_dfs(int cnt, int y, int x) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visited_labeling[ny][nx] == 1)
			continue;
		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			continue;
		if (map[ny][nx] == 1) {
			visited_labeling[ny][nx] = 1;
			labeling[ny][nx] = cnt;
			labeling_dfs(cnt, ny, nx);
		}
	}
}

void check_bridge(int y, int x, int dir, int cur_labeling) {
	if (map[y + dy[dir]][x + dx[dir]] != 0)
		return;
	int cnt = 1;
	while (1) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			return;
		if (labeling[ny][nx] == cur_labeling)
			return;	
		if (map[ny][nx] == 1 && labeling[ny][nx] != cur_labeling) {
			if (graph[cur_labeling][labeling[ny][nx]] > cnt) {
				graph[cur_labeling][labeling[ny][nx]] = cnt;
				graph[labeling[ny][nx]][cur_labeling] = cnt;
			}
			return;
		}
		x = nx;
		y = ny;
		cnt++;
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	//int labeling_count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			graph[i][j] = 9999;
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && visited_labeling[i][j] == 0) {
				cnt++;
				labeling[i][j] = cnt;
				visited_labeling[i][j] = 1;
				labeling_dfs(cnt, i, j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (labeling[i][j] != 0) {
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx < 0 || ny < 0 || nx >= M || ny >= N)
						continue;
					if (map[ny][nx] == 0) {
						check_bridge(ny, nx, k, labeling[i][j]);	//k는 현재 방향으로
					}
				}
			}
		}
	}

	if (cnt > 7) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (graph[i][j] == 9999)
				graph[i][j] = 0;
		}
	}

	//prim 알고리즘 수행

	priority_queue<pos, vector<pos>, cmp> pq;
	visited_vertex[1] = 1;
	vertex_dist[1] = 0;
	for (int i = 1; i <= cnt; i++) {
		if (graph[1][i] != 0) {
			int next_vertex = i;
			int next_cost = graph[1][i];
			pq.push(pos(next_vertex, next_cost));
		}
	}

	int ans = 0;

	while (!pq.empty()) {
		int here = pq.top().next_vertex;
		int here_cost = pq.top().next_cost;
		pq.pop();

		if (visited_vertex[here] == 1)
			continue;

		visited_vertex[here] = 1;

		ans += here_cost;
		for (int i = 1; i <= cnt; i++) {
			if (graph[here][i] != 0) {
				int next_vertex = i;
				int next_cost = graph[here][i];
				pq.push(pos(next_vertex, next_cost));
			}
		}

	}

	bool flag = false;

	for (int i = 1; i <= cnt; i++) {
		if (visited_vertex[i] == 0)
			flag = true;
	}

	if (ans == 0 || flag == true)
		cout << -1 << endl;
	else
		cout << ans << endl;

	return 0;
}
