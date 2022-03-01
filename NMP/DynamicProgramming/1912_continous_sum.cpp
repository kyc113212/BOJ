#include <iostream>

using namespace std;

int N;
int arr[100005];
int DP[100005];

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	fill(DP, DP + N, -987654321);
	int ans = 0;
	ans = arr[0];
	DP[0] = arr[0];

	for (int i = 1; i < N; i++) {
		DP[i] = max(DP[i - 1] + arr[i], arr[i]);
		ans = max(DP[i], ans);
	}

	cout << ans << '\n';

	return 0;
}
