// 이전에 풀었던 문제인데 까먹었다.
// 최장 부분문자열에 대해서 더 공부하고 2차원 배열 DP에 대해서 더 공부해야한다.
// 지나간 문자열 유추하는 것도 다시 공부할 것

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int DP[1001][1001];
string rst;
string s1, s2;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s1 >> s2;

	for (int i = 1; i <= s2.size(); i++) {
		for (int j = 1; j <= s1.size(); j++) {
			if (s2[i-1] == s1[j-1]) {
				DP[i][j] = DP[i-1][j-1] + 1;
			}
			else {
				DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
			}
		}
	}

	int s1_size = s1.size();
	int s2_size = s2.size();
	
	while (DP[s2_size][s1_size]) {
		if (DP[s2_size][s1_size] == DP[s2_size][s1_size - 1]) {
			s1_size--;
		}
		else if (DP[s2_size][s1_size] == DP[s2_size - 1][s1_size]) {
			s2_size--;
		}
		else if (DP[s2_size][s1_size] - 1 == DP[s2_size - 1][s1_size - 1]) {
			rst += s1[s1_size - 1];
			s1_size--;
			s2_size--;
		}
	}

	if (DP[s2.size()][s1.size()]) {
		cout << DP[s2.size()][s1.size()] << '\n';
		for (int i = rst.size() - 1; i >= 0; i--) {
			cout << rst[i];
		}
		cout << '\n';
	}
	else
		cout << DP[s2.size()][s1.size()] << '\n';

	return 0;
}
