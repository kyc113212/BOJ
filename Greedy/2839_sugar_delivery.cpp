#include <iostream>
#include <algorithm>

using namespace std;

#define INF 987654321

int N;
int DP[5005];
int arr[2] = { 3,5 };

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		DP[i] = INF;
	}	

	DP[3] = 1;
	DP[5] = 1;

	for (int i = 0; i < 2; i++) {
		for (int j = arr[i]; j <= N; j++) {
			DP[j] = min(DP[j], DP[j - arr[i]] + 1);
		}
	}

	if (DP[N] == INF)
		cout << -1 << '\n';
	else
		cout << DP[N] << '\n';

	return 0;
}
