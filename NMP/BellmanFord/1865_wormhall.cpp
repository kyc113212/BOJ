#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 987654321

struct info {
	int v, d;
	info(int a, int b) : v(a), d(b) {}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int N, M, W;
		cin >> N >> M >> W;
		int dist[505];
		fill(dist, dist + N + 1, INF);
		vector<info> graph[505];
		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			graph[a].push_back(info(b, c));
			graph[b].push_back(info(a, c));
		}

		for (int i = 0; i < W; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			graph[a].push_back(info(b, c*(-1)));
		}

		//모든 지점에서의 출발점을 찾아봐야한다.
		dist[1] = 0;
		bool minus_cycle = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (auto &p : graph[j]) {
					int n_v = p.v;
					int n_d = p.d;
					if (dist[j] + n_d < dist[n_v]) {
						dist[n_v] = dist[j] + n_d;
						if (i == N) {
							minus_cycle = true;
						}
					}
				}
			}
		}
		

		if (minus_cycle) {
			cout << "YES" << '\n';
		}
		else
			cout << "NO" << '\n';
	}


	return 0;
}
