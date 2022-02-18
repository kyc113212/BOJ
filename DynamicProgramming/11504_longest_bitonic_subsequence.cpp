#include <iostream>
#include <algorithm>

using namespace std;

int DP[1005];
int DP_R[1005];
int arr[1005];
int N;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	DP[0] = DP_R[N-1] = 1;

	for (int i = 0; i < N; i++) {
		if (DP[i] == 0)
			DP[i] = 1;
		for (int j = i+1; j < N; j++) {
			if ((arr[i] < arr[j]) && (DP[j] < DP[i] + 1)) {
				DP[j] = DP[i] + 1;
			}
		}
	}
	for (int i = N-1; i >= 0; i--) {
		if (DP_R[i] == 0)
			DP_R[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if ((arr[i] < arr[j]) && (DP_R[j] < DP_R[i] + 1)) {
				DP_R[j] = DP_R[i] + 1;
			}
		}
	}
	
	int maxV = 0;
	for (int i = 0; i < N; i++) {
		maxV = max(maxV, DP[i] + DP_R[i] - 1);
	}

	cout << maxV << '\n';


	return 0;
}
