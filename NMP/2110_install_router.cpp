#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, M;
ll arr[200005];

int main() {

	cin >> N >> M;
	ll lo = 1000000005;
	ll hi = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	hi = arr[N - 1] - arr[0];
	for (int i = 0; i < N - 1; i++) {
		lo = min(arr[i + 1] - arr[i], lo);
	}

	ll result = 0;

	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		ll cnt = 0;
		ll prev_house = arr[0];
		for (int i = 1; i < N; i++) {
			if (arr[i] - prev_house >= mid) {
				cnt++;
				prev_house = arr[i];
			}
		}
		cnt++;
		if (cnt >= M) {
			result = max(result, mid);
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}

	cout << result << '\n';


	return 0;
}
