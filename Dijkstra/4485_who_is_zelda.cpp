#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define INF 987654321

using namespace std;


struct item {
	int y, x, weight;
	item(int a, int b, int c) :y(a), x(b), weight(c) {}
};

struct cmp {
	bool operator() (item &a, item &b) {
		return a.weight > b.weight;
	}
};

int N;
int map[130][130];
int visited[130][130];

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int bfs() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = INF;
		}
	}

	priority_queue<item, vector<item>, cmp > pq;
	pq.push(item(0, 0, map[0][0]));
	visited[0][0] = map[0][0];

	while (!pq.empty()) {

		int cy = pq.top().y;
		int cx = pq.top().x;
		int c_weight = pq.top().weight;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (visited[ny][nx] > visited[cy][cx] + map[ny][nx]) {
				int n_cost = c_weight + map[ny][nx];
				visited[ny][nx] = n_cost;
				pq.push(item(ny, nx, n_cost));
			}
		}

	}
	

	return visited[N - 1][N - 1];

}

int main() {
	int i = 1;
	while (1) {
		cin >> N;
		memset(map, 0, sizeof(map));
		//memset(visited, INF, sizeof(visited));
		if (N == 0)
			break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		cout << "Problem " << i << ": " << bfs() << '\n';
		i++;
	}


	return 0;
}
