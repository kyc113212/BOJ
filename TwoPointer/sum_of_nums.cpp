#include <iostream>

using namespace std;
int N, M;
int arr[10001];

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int ans = 0;
	int start = 0;
	int end = 0;
	int sum = arr[0];

	while (start < N && end < N) {
		if (sum == M) {
			ans++;
		}
		if (sum >= M) {
			sum -= arr[start++];
		}
		else {
			sum += arr[++end];
		}
	}

	cout << ans << endl;

	return 0;
}
