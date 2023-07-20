#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int slt[5002];
bool done[5002];
vector<int> graph[5002];
int N, M;

bool dfs(int x) {

	for (int i = 0; i < graph[x].size(); i++) {
		int p = graph[x][i];
		if (done[p])
			continue;
		done[p] = true;
		if (slt[p] == 0 || dfs(slt[p])) {
			slt[p] = x;
			return true;
		}
	}

	return false;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		memset(done, false, sizeof(done));
		if (dfs(i)) {
			cnt++;
		}
	}

	cout << cnt << '\n';


	return 0;
}
