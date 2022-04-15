#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int V, E;
int node_color[20001];
vector<int> graph[20001];
bool visited[20001];

bool check_binary_graph() {
	queue<int> q2;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= V; i++) {
		if (visited[i] == false) {
			q2.push(i);
			node_color[i] = 1;
			while (!q2.empty()) {
				int c_v = q2.front();
				q2.pop();
				if (visited[c_v])
					continue;
				visited[c_v] = true;
				int cur_color = node_color[c_v];
				for (int i = 0; i < graph[c_v].size(); i++) {
					int next_v = graph[c_v][i]; 
					if (visited[next_v])
						continue;
					if (cur_color == 1)
						node_color[next_v] = 2;
					else if (cur_color == 2) {
						node_color[next_v] = 1;
					}
					q2.push(next_v);
				}
			}
		}
	}

	queue<int> q;
	for (int i = 1; i <= V; i++) {
		q.push(i);
	}
	memset(visited, false, sizeof(visited));
	while (!q.empty()) {
		int cur_v = q.front();
		q.pop();
		if (visited[cur_v])
			continue;
		visited[cur_v] = true;
		int cur_color = node_color[cur_v];
		for (int i = 0; i < graph[cur_v].size(); i++) {
			int next_v = graph[cur_v][i];
			if (cur_color == node_color[next_v])
				return false;
			if (visited[next_v])
				continue;
			q.push(next_v);
		}
	}

	return true;
}




int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		memset(node_color, 0, sizeof(node_color));
		cin >> V >> E;
		
		for (int i = 1; i <= V; i++) {
			graph[i].clear();
		}
		int ans = 0;
		for (int i = 0; i < E; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		if (check_binary_graph()) {
			// 점을 주어준 다음에 다시 한번 탐색
			cout << "YES" << '\n';
		}
		else
			cout << "NO" << '\n';
	}

	return 0;

}
