#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 987654321

int N, M;
int b[101], cost[101];
int DP[101][10001];

int main() {

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
	}
	int ans = 100001;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 10001; j++) {
			if (cost[i] <= j) {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - cost[i]] + b[i]);
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j]);
			}
			if (DP[i][j] >= M) {
				ans = min(ans, j);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
