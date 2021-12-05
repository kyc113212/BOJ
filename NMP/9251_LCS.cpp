#include <iostream>
#include <string>

using namespace std;
int DP[1002][1002];

int main() {

	string A, B;
	int ans = 0;
	cin >> A >> B;

	for (int i = 1; i <= A.size(); i++) {
		for (int j = 1; j <= B.size(); j++) {
			if (A[i - 1] == B[j - 1]) {
				DP[i][j] = DP[i-1][j-1] + 1;
				ans = max(DP[i][j], ans);
			}
			else {
				DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
				ans = max(DP[i][j], ans);
			}
		}
	}

	cout << ans << '\n';


	return 0;
}
