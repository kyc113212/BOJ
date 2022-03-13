// 연속적인 값들의 합을 구하는 방법을 계속 놓친다
// 점화식 세우는 연습을 더 해볼 것

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int DP[100005][2];
int arr[100005];

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	
	DP[1][0] = arr[1];
	DP[1][1] = arr[1];
	int ans = arr[1];
	for (int i = 2; i <= N; i++) {
		DP[i][0] = max(DP[i - 1][0] + arr[i], arr[i]);
		DP[i][1] = max(DP[i - 1][0], DP[i - 1][1] + arr[i]);
		ans = max(ans, max(DP[i][0], DP[i][1]));
	}

	cout << ans << '\n';
	return 0;
}
