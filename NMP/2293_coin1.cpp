#include <iostream>

using namespace std;

int DP[10005];
int arr[105];
int N, K;

int main() {

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	DP[0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = arr[i]; j <= K; j++) {
			DP[j] = DP[j] + DP[j - arr[i]];
		}
	}

	cout << DP[K] << '\n';

	return 0;
}
