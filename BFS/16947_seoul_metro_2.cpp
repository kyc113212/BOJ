#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

#define MAX_V 987654321
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<int> graph[3001];
int N;
bool done[3001];
bool loop[3001];
bool visited[3001];

int dfs(int s, int next, int cnt) {
	if (s == next && cnt > 2) {
		return true;
	}
	if (done[next]) {
		return false;
	}
	done[next] = true;
	for (int i = 0; i < graph[next].size(); i++) {
		if (dfs(s, graph[next][i], cnt + 1)) {
			return loop[graph[next][i]] = true;
		}
	}

	return false;
}

int find_route(int v) {
	memset(visited, false, sizeof(visited));
	queue<pair<int,int>> q;
	q.push(make_pair(v,0));
	while (!q.empty()) {
		int nv = q.front().first;
		int ncnt = q.front().second;
		q.pop();
		
		if (loop[nv]) {
			return ncnt;
		}
		if (visited[nv])
			continue;
		visited[nv] = true;
		for (int i = 0; i < graph[nv].size(); i++) {
			int nnv = graph[nv][i];
			if (visited[nnv])
				continue;
			q.push(make_pair(nnv, ncnt + 1));
		}
	}
}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		memset(done, false, sizeof(done));
		done[i] = true;
		for (int j = 0; j < graph[i].size(); j++) {
			if (dfs(i, graph[i][j], 1)) {
				loop[i] = true;
				break;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (loop[i]) {
			cout << 0 << ' ';
		}
		else {
			// 길이값을 찾아준다.
			cout << find_route(i) << ' ';
		}
	}
	cout << '\n';
	
	return 0;
}
