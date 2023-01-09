#include <iostream>

using namespace std;

#define MOD 1000000000

int N;
int DP[101][10][1 << 10];
int full = (1 << 10) - 1;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i < 10; i++) {
		DP[1][i][1 << i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 1 << 10; k++) {
				if (j == 0) {
					//현재 것에 포함시켜야함
					int m = (k | (1 << j));
					DP[i][j][m] = (DP[i][j][m]+ DP[i - 1][j + 1][k]) % MOD;
				}
				else if (j == 9) {
					int m = (k | (1 << j));
					DP[i][j][m] = (DP[i][j][m] + DP[i - 1][j - 1][k]) % MOD;
				}
				else {
					int m = (k | (1 << j));
					DP[i][j][m] = (DP[i][j][m] + DP[i - 1][j + 1][k]) % MOD;
					DP[i][j][m] = (DP[i][j][m] + DP[i - 1][j - 1][k]) % MOD;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans = (ans + DP[N][i][full]) % MOD;
	}

	cout << ans << '\n';


	return 0;
}
