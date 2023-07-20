#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool done[1005];
int oc[1005];
int N, M;
vector<int> graph[1005];

bool dfs(int x) {

	for (int i = 0; i < graph[x].size(); i++) {
		int p = graph[x][i];
		if (done[p])
			continue;
		done[p] = true;
		if (oc[p] == 0 || dfs(oc[p])) {
			oc[p] = x;
			return true;
		}
	}
	return false;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			graph[i].push_back(b);
		}
	}

	int cnt = 0;
	for (int j = 0; j < 2; j++) {
		for (int i = 1; i <= N; i++) {
			memset(done, false, sizeof(done));
			if (dfs(i)) {
				cnt++;
			}
		}
	}

	cout << cnt << '\n';


	return 0;
}
