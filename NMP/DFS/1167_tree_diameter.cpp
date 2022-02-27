#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct info {
	int vertex, dist;
	info(int a, int b) : vertex(a), dist(b) {}
};

int N;
string s;
vector<info> graph[100001];
int visited[100001];
int maxV = 0;
int maxIndex = -1;

void dfs(int vertex, int dist) {

	if (dist > maxV) {
		maxV = dist;
		maxIndex = vertex;
	}

	for (int i = 0; i < graph[vertex].size(); i++) {
		int next_v = graph[vertex][i].vertex;
		int n_dist = graph[vertex][i].dist;
		if (visited[next_v])
			continue;
		visited[next_v] = 1;
		dfs(next_v, n_dist + dist);
	}
	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<info> v;
		vector<int> tv;
		int node;
		cin >> node;
		while (1) {
			int a;
			cin >> a;
			if (a == -1)
				break;
			tv.push_back(a);
		}
		for (int i = 0; i < tv.size(); i += 2) {
			graph[node].push_back(info(tv[i], tv[i + 1]));
		}
	}

	// 1에서부터 가장 먼점의 vertex 구한 뒤
	// 그 vertex에서 가장 긴 길이 구하면됨
	memset(visited, 0, sizeof(visited));
	visited[1] = 1;
	dfs(1, 0);

	memset(visited, 0, sizeof(visited));
	visited[maxIndex] = 1;
	dfs(maxIndex, 0);

	cout << maxV << '\n';

	return 0;
}
