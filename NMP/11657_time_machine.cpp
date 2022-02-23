#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

struct info {
	int n, d;
	info(int a, int b) : n(a), d(b) {}
};

vector<info> graph[505];
long long dist[505];
int N, M;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(info(b, c));
	}
	fill(dist, dist + N + 1, INF);

	dist[1] = 0;
	bool minus_circle = false;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (auto& p : graph[j]) {
				int n_v = p.n;
				int n_d = p.d;
				if (dist[j] != INF && dist[j] + n_d < dist[n_v]) {
					dist[n_v] = dist[j] + n_d;
					if (i == N) {
						minus_circle = true;
					}
				}
			}
		}
	}
	
	if (minus_circle)
		cout << -1 << '\n';
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF)
				cout << -1 << '\n';
			else
				cout << dist[i] << '\n';
		}
	}
	


	return 0;
}
