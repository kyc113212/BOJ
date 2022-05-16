#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;

int N, K;
ll M;
ll DP[100001][31];
ll start_c[100001];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> M;

	for (int i = 1; i <= N; i++) {
		cin >> start_c[i];
	}
	
	for (int i = 1; i <= K; i++) {
		cin >> DP[i][0];
	}

	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j < 100001; j++) {
			DP[j][i] = DP[DP[j][i - 1]][i - 1];
		}
	}
	for (int i = 1; i <= N; i++) {
		int s_v = start_c[i];
		for (int j = 30; j >= 0; j--) {
			if ((M-1) & (1 << j)) {
				s_v = DP[s_v][j];
			}
		}
		cout << s_v << ' ';
	}
	cout << '\n';

	return 0;
}
