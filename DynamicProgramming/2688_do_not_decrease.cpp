#include <iostream>

using namespace std;
typedef unsigned long long ull;

ull DP[65][10];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 10; i++) {
		DP[1][i] = 1;
	}

	for (int i = 2; i <= 64; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				DP[i][j] += DP[i - 1][k];
			}
		}
	}

	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int N;
		cin >> N;	

		ull ans = 0;
		for (int i = 0; i < 10; i++) {
			ans += DP[N][i];
			
		}

		cout << ans << '\n';
	}

	return 0;
}
