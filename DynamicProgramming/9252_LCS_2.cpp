// 이전에 풀었던 문제인데 까먹었다.
// 최장 부분문자열에 대해서 더 공부하고 2차원 배열 DP에 대해서 더 공부해야한다.

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int N;
int DP[1005][1005];
int arr[1005];
string P[1005][1005];
string s1, s2;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s1 >> s2;

	for (int i = 1; i <= s2.size(); i++) {
		for (int j = 1; j <= s1.size(); j++) {
			if (s2[i-1] == s1[j-1]) {
				DP[i][j] = DP[i-1][j-1] + 1;
				P[i][j] = P[i - 1][j - 1] + s2[i - 1];
			}
			else {
				DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
				P[i][j] = P[i - 1][j].size() > P[i][j-1].size() ? P[i - 1][j] : P[i][j - 1];
			}
		}
	}

	if (DP[s2.size()][s1.size()]) {
		cout << DP[s2.size()][s1.size()] << '\n' << P[s2.size()][s1.size()] << '\n';
	}
	else
		cout << DP[s2.size()][s1.size()] << '\n';

	return 0;
}
