#include <iostream>
#include <cstring>

using namespace std;

long long DP[31][61];

int main() {

	while (1) {
		
		int N;
		cin >> N; 
		if (N == 0)
			break;
		memset(DP, 0, sizeof(DP));
		DP[1][0] = 1;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0) {
					DP[i][j] = 1;
				}
				else {
					DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
				}
			}
		}
		cout << DP[N][N] << '\n';
	}

	return 0;
}
