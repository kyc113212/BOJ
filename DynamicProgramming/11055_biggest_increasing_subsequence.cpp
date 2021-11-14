#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

int N;
int arr[1001], DP[1001];

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	DP[0] = arr[0];
	for (int i = 0; i < N; i++) {
		DP[i] = max(arr[i],DP[i]);
		for (int j = i; j < N; j++) {
			if (arr[j] > arr[i] && DP[i] + arr[j] > DP[j]) {
				DP[j] = DP[i] + arr[j];
			}
		}
	}

	int maxV = 1;
	for (int i = 0; i < N; i++) {
		maxV = max(maxV, DP[i]);
	}

	cout << maxV << endl;

	return 0;
}
