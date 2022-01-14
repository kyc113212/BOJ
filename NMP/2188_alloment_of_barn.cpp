#include <iostream>
#include <vector>
#include <cstring>
#define MAX 501

using namespace std;

vector<int> v[MAX];
bool done[MAX];
int oc[MAX];
int N, M;

bool dfs(int x) {

	for (int i = 0; i < v[x].size(); i++) {
		int p = v[x][i];
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
			v[i].push_back(b);
		}
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
