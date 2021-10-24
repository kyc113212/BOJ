#include <iostream>
#include <cstring>

using namespace std;

int DP[41];
int count_zero[41];
int count_one[41];

int fibo(int n) {
	if (DP[n] != -1) {
		return DP[n];
	}
	else if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else {
		DP[n] = fibo(n - 1) + fibo(n - 2);
		count_zero[n] = count_zero[n - 1] + count_zero[n - 2];
		count_one[n] = count_one[n - 1] + count_one[n - 2];
		return DP[n];
	}
}

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		memset(DP, -1, sizeof(DP));
		memset(count_zero, 0, sizeof(count_zero));
		memset(count_one, 0, sizeof(count_one));
		DP[0] = 0;
		DP[1] = 1;
		count_one[1] = 1;
		count_zero[0] = 1;
		fibo(N);
		cout << count_zero[N] << " " << count_one[N] << '\n';
	}

	return 0;
}
