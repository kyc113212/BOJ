#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[305];
int DP[305];

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	DP[1] = arr[1];
	DP[2] = max(arr[2], arr[1] + arr[2]);
	DP[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

	for (int i = 4; i <= N; i++) {
		DP[i] = max(DP[i - 3] + arr[i] + arr[i-1], DP[i - 2] + arr[i]);
	}

	cout << DP[N] << '\n';

	return 0;
}
