#include <iostream>
#include <algorithm>

using namespace std;

long long N, S;
long long arr[100001];

int solve() {
	int o = 0;
	int t = 0;
	long long sum = arr[0];
	int ans = 987654321;

	while (o < N && t< N) {	//o < N

		if (t == N-1 && o == 0 && sum < S)
			break;

		if (sum >= S) {
			ans = min(ans, t - o + 1);
		}

		if (sum <= S) {
			sum += arr[++t];
		}
		else if (sum > S) {
			o++;
			sum -= arr[o - 1];
		}
	}

	return ans;
}

int main() {

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	long long ans = solve();
	if (ans == 987654321)
		cout << 0 << '\n';
	else
		cout << solve() << '\n';

	return 0;
}
