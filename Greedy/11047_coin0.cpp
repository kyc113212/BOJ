#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[11];

int main() {

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N, greater<>());
	int i = 0;
	int cnt = 0;
	while (1) {
		if (K == 0) {
			break;
		}
		if (arr[i] <= K) {
			int j = 1;
			for (; j*arr[i] <= K; j++);
			cnt += (j-1);
			K -= (j-1) * arr[i];
		}
		else {
			i++;
		}
			
	}

	cout << cnt << endl;

	return 0;
}
