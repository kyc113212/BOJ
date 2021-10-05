#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>

#define MAX 10001

using namespace std;

deque<int> graph[MAX];
int visited[MAX];

int bfs(int v) {

	int cnt = 1;
	memset(visited, 0, sizeof(visited));
	visited[v] = 1;
	deque<int> dq;
	dq.push_back(v);

	while (!dq.empty()) {
		int c_v = dq.front();
		dq.pop_front();
		for (int i = 0; i < graph[c_v].size(); i++) {
			int n_v = graph[c_v][i];
			if (!visited[n_v]) {
				visited[n_v] = 1;
				cnt++;
				dq.push_back(n_v);
			}
		}
	}

	return cnt;
}


int main() {

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}

	int maxV = 0;
	deque<pair<int, int>> rst;

	for (int i = 1; i <= N; i++) {
		int cnt = bfs(i);
		if (cnt >= maxV) {
			maxV = cnt;
			rst.push_back(make_pair(i, cnt));
		}
	}

	for (int i = 0; i < rst.size(); i++) {
		if (maxV == rst[i].second) {
			cout << rst[i].first << " ";
		}
	}
	cout << endl;
	

	return 0;
}
