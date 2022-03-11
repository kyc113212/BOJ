#include <iostream>

using namespace std;

int N;
int arr[105];
long long DP[105][21];

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	DP[0][arr[0]] = 1;

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (DP[i][j]) {
				int p = j + arr[i+1];
				int m = j - arr[i+1];
				if (p <= 20) {
					DP[i+1][p] += DP[i][j];
				}
				if (m >= 0) {
					DP[i+1][m] += DP[i][j];
				}
			}
		}
	}

	cout << DP[N - 2][arr[N - 1]] << '\n';

	return 0;
}
