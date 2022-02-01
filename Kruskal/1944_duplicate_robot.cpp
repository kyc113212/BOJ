#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct info {
	int vertex, dist;
	info(int a, int b) : vertex(a), dist(b) {}
};

struct pos {
	int y, x, cnt;
	pos(int a, int b, int c) : y(a), x(b), cnt(c) {}
};

struct cmp {
	bool operator()(info& a, info& b) {
		return a.dist > b.dist;
	}
};

int N, M;
int map[51][51];
vector<info> graph[255];
vector<pair<int, int>> loc;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

void make_graph(int y, int x, int vertex) {
	bool visited[55][55];
	memset(visited, false, sizeof(visited));
	queue<pos> q;
	q.push(pos(y, x, 0));
	visited[y][x] = true;

	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		int c_cnt = q.front().cnt;
		q.pop();

		if (map[cy][cx] == 2) {//다음 vertex가 있는 경우
			for (int i = 0; i < loc.size(); i++) {
				if (y == cy && x == cx)
					continue;
				if (loc[i].first == cy && loc[i].second == cx) {
					graph[vertex].push_back(info(i, c_cnt));
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny >= N || nx >= N || ny < 0 || nx < 0)
				continue;
			if (visited[ny][nx])
				continue;
			if (map[ny][nx] == 1)
				continue;
			visited[ny][nx] = true;
			q.push(pos(ny, nx, c_cnt + 1));
		}
	
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	//S위치 부터 조사
	//나머지 K도 조사
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == '0')
				map[i][j] = 0;
			else if (s[j] == '1')
				map[i][j] = 1;
			else if (s[j] == 'K' || s[j] == 'S') {
				map[i][j] = 2;
				loc.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < loc.size(); i++) {
		make_graph(loc[i].first, loc[i].second, i);
	}

	//graph준비 완료
	int ans = 0;
	int cnt = loc.size()-1;
	bool visited[255];
	memset(visited, false, sizeof(visited));
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 0; i < graph[0].size(); i++) {
		pq.push(info(graph[0][i].vertex, graph[0][i].dist));
	}
	visited[0] = true;

	while (!pq.empty()) {
		int c_v = pq.top().vertex;
		int c_d = pq.top().dist;
		pq.pop();

		if (visited[c_v])
			continue;
		cnt--;
		ans += c_d;
		visited[c_v] = true;

		for (int i = 0; i < graph[c_v].size(); i++) {
			int n_v = graph[c_v][i].vertex;
			int n_d = graph[c_v][i].dist;
			if (visited[n_v])
				continue;
			pq.push(info(n_v, n_d));
		}
	}

	if (cnt == 0) {
		cout << ans << '\n';
	}
	else
		cout << -1 << '\n';
	
	return 0;
}
