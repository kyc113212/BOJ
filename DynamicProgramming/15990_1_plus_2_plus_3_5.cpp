#include <iostream>
#include <cstring>

using namespace std;

#define MOD 1000000009

long long DP[100005][4];

int main() {

	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int N;
		cin >> N;
		memset(DP, 0, sizeof(DP));
		DP[1][1] = 1;
		DP[2][2] = 1;
		DP[3][3] = 1;

		for (int i = 3; i <= N; i++) {
			DP[i][1] += (DP[i - 1][2] + DP[i - 1][3]) % MOD;
			DP[i][2] += (DP[i - 2][1] + DP[i - 2][3]) % MOD;
			DP[i][3] += (DP[i - 3][1] + DP[i - 3][2]) % MOD;
		}
		
		cout << (DP[N][1] + DP[N][2] + DP[N][3]) % MOD << '\n';
	}

	return 0;
}
