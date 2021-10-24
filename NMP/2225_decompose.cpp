#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, K;
int DP[202][202];

int main() {

	cin >> N >> K;
	for (int i = 0; i <= N; i++) {
		DP[1][i] = 1;
	}

	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				DP[i][j] = (DP[i][j] + DP[i - 1][j - k]) % 1000000000;
			}
		}
	}

	cout << DP[K][N] << '\n';

	return 0;
}
