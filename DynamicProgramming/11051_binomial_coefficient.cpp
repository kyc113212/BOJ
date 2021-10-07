#include <iostream>

using namespace std;

int DP[1001][1001];

int main() {

	int N, K;
	cin >> N >> K;
	DP[0][0] = 1;
	DP[1][0] = 1;
	DP[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				DP[i][j] = 1;
			}
			else if (i == j) {
				DP[i][j] = 1;
			}
			else
			{
				DP[i][j] = (DP[i - 1][j - 1] % 10007) + (DP[i - 1][j] % 10007);
			}
		}
	}

	cout << DP[N][K] % 10007 << endl;

	return 0;
}
