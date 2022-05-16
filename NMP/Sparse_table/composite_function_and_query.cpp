#include <iostream>
#include <algorithm>

using namespace std;

int M;
int DP[200001][21];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> DP[i][0];
	}

	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= M; j++) {
			DP[j][i] = DP[DP[j][i - 1]][i - 1];
		}
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int n, x;
		cin >> n >> x;
		for (int j = 20; j >= 0; j--) {
			if (n & (1 << j)) {
				x = DP[x][j];
			}
		}
		cout << x << '\n';
	}

	return 0;
}
