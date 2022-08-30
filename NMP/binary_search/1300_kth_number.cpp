#include <iostream>
#include <algorithm>

using namespace std;

int ans = 0;
int N = 0;
int K = 0;

int main() {

	cin >> N >> K;

	int left = 1;
	int right = K;
	int mid = 0;
	int ans = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			cnt += min(mid / i, N);
		}
		if (cnt >= K) {
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << ans << '\n';

	return 0;
}
