#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[501][501];
int DP[501][501];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i+1; j++) {
			cin >> arr[i][j];
		}
	}

	DP[0][0] = arr[0][0];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) {
				DP[i][j] = DP[i - 1][j] + arr[i][j];
			}
			else if (j == i) {
				DP[i][j] = DP[i - 1][j - 1] + arr[i][j];
			}
			else {
				DP[i][j] = max(DP[i - 1][j - 1] + arr[i][j], DP[i - 1][j] + arr[i][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, DP[N - 1][i]);
	}

	cout << ans << '\n';

	return 0;
}
