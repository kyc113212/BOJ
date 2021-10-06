#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAX 10001

using namespace std;

int hack[MAX];
int visited[MAX];
vector<int> graph[MAX];
int N, M;

void dfs(int v) {
	visited[v] = 1;

	for (int i = 0; i < graph[v].size(); i++) {
		int  next_v = graph[v][i];
		if (!visited[next_v]) {
			visited[next_v] = 1;
			hack[next_v]++;
			dfs(next_v);
		}
	}
}

int main() {
	 
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	int maxV = 0;

	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i);
	}

	for (int i = 1; i <= N; i++) {
		maxV = max(maxV, hack[i]);
	}

	for (int i = 1; i <= N; i++) {
		if (hack[i] == maxV) {
			cout << i << " ";
		}
	}
	cout << endl;

	return 0;
}
