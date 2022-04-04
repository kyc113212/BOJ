#include <iostream>

using namespace std;
typedef long long ll;

ll DP[41];
bool check_vip[41];

int main() {

	int N, M;
	cin >> N >> M;
	DP[0] = 1;
	DP[1] = 1;
	DP[2] = 2;
	for (int i = 3; i <= N; i++) {
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		check_vip[a] = true;
	}

	int ans = 1;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (i == N && !check_vip[i]) {
			cnt++;
			ans *= DP[cnt];
			cnt = 0;
		}
		else if (check_vip[i] == true) {
			ans *= DP[cnt];
			cnt = 0;
		}
		else
			cnt++;
	}
	cout << ans << '\n';
	
	return 0;
}
