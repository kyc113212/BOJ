// 9471

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>
#include <queue>

#define MAX_V 987654321
#define MOD 100000009
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool visited[100001];
int dist[100001];
vector<int> graph[100001];

int main() {

	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, R;
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	queue<int> q;
	visited[R] = true;
	dist[R] = 1;
	for (int i = 0; i < graph[R].size(); i++) {
		q.push(graph[R][i]);
	}
	int cnt = 2;

	while (!q.empty()) {
		int q_size = q.size();
		vector<int> tv;
		for (int i = 0; i < q_size; i++) {
			int v = q.front();
			q.pop();
			if (visited[v])
				continue;
			visited[v] = true;
 			dist[v] = cnt++;
			for (int j = 0; j < graph[v].size(); j++) {
				if (visited[graph[v][j]])
					continue;
				q.push(graph[v][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << dist[i] << '\n';
	}

	return 0;
}
