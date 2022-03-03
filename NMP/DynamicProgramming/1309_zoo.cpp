#include <iostream>

using namespace std;

#define MOD 9901

int N;
int DP[100005][3];

int main() {

	ios_base::sync_with_stdio(false);

	cin >> N;

	DP[1][0] = 1;
	DP[1][1] = 1;
	DP[1][2] = 1;

	for (int i = 2; i <= N; i++) {
		DP[i][0] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % MOD;
		DP[i][1] = (DP[i - 1][0] + DP[i - 1][2]) % MOD;
		DP[i][2] = (DP[i - 1][0] + DP[i - 1][1]) % MOD;
	}

	cout << (DP[N][0] + DP[N][1] + DP[N][2]) % MOD << '\n';

	return 0;
}
