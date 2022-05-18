#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct info {
	int to, weight;
	info(int t, int w) : to(t), weight(w) {}
};

bool cmp(info &a, info &b) {
	return a.weight > b.weight;
}

int N, M;
int A,B;
bool visited[10001];
vector<info> graph[10001];

bool bfs(int w) {

	queue<info> q;
	memset(visited, false, sizeof(visited));
	visited[A] = true;
	for (int i = 0; i < graph[A].size(); i++) {
		if(graph[A][i].weight >= w)
			q.push(info(graph[A][i].to,graph[A][i].weight));
	}

	while (!q.empty()) {
		int cv = q.front().to;
		int c_weight = q.front().weight;
		q.pop();
		if (visited[cv])
			continue;
		visited[cv] = true;
		if (cv == B)
			return true;
		for (int i = 0; i < graph[cv].size(); i++) {
			int nv = graph[cv][i].to;
			int n_weight = graph[cv][i].weight;
			if (visited[nv])
				continue;
			if (n_weight < w)
				continue;
			q.push(info(nv, n_weight));
		}
	}

	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	int left = 0;
	int right = 0;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(info(b, c));
		graph[b].push_back(info(a, c));
		right = max(right, c);
	}
	cin >> A >> B;

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end(), cmp);
	}

	int mid = (left + right) / 2;
	while (left <= right) {
		mid = (left + right) / 2;
		if (bfs(mid)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << right << '\n';

	return 0;
}
