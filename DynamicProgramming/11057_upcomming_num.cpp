#include <iostream>

using namespace std;

long long DP[1002][11];

int main() {

	int N;
	cin >> N;
	for (int i = 0; i < 10; i++) {
		DP[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				DP[i][j] += (DP[i - 1][k] % 10007);
			}
		}
	}

	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += (DP[N][i] % 10007);
	}

	cout << sum % 10007 << endl;

	return 0;
}
