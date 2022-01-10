#include <algorithm>
#include <iostream>

using namespace std;

int N;
int arr[100005];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	int cnt = 1;
	int maxV = 0;
	int sum = 0;

	for (int i = N - 1; i >= 0; i--) {
		sum += arr[i];
		maxV = max(maxV, (arr[i] * cnt));
		cnt++;
	}

	cout << maxV << '\n';
	
	return 0;
}
