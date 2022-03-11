#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
int map[1005][1005];
int DP[1005][1005];

int main() {

	cin >> N >> M;
	int maxV = 0;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i+1][j+1] = s[j] - '0';
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 1) {
				DP[i][j] = min(DP[i][j - 1], min(DP[i - 1][j], DP[i - 1][j - 1])) + 1;
				maxV = max(DP[i][j], maxV);
			}
		}
	}

	cout << maxV * maxV << '\n';


	return 0;
}
