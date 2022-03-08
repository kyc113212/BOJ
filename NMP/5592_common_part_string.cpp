#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int DP[4005][4005];

int main() {

	string s1, s2;
	cin >> s1 >> s2;
	int maxV = 0;

	for (int i = 0; i < s2.size(); i++) {
		for (int j = 0; j < s1.size(); j++) {
			if (s1[j] == s2[i]) {
				DP[i+1][j+1] = DP[i][j] + 1;
				maxV = max(maxV, DP[i + 1][j + 1]);
			}
		}
	}
	cout << maxV << '\n';

	return 0;
}
