#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>
#include <queue>

#define MAX_V 987654321
#define MOD 100000007
#define T_MAX_V 1000000000
#define TREE_HEIGHT 20
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int N, K;

string solve() {

	bool flag = false;
	for (int i = 1; i <= N; i++) {
		int a = i;
		int b = N - i;
		if (a*b < K) {
			continue;
		}
		else {
			flag = true;
			string s = "";
			for (int j = 0; j < a - 1; j++) {
				s += 'A';
			}
			for (int j = 0; j < N - a + 1; j++) {
				s += 'B';
			}
			for (int j = N - 1; j >= a - 1; j--) {
				s[j] = 'A';
				// 쌍 계산 시작
				int k_cnt = 0;
				for (int k = 0; k < N; k++) {
					if (s[k] == 'A') {
						for (int m = k + 1; m < N; m++) {
							if (s[m] == 'B') {
								k_cnt++;
							}
						}
					}
				}
				if (k_cnt == K) {
					return s;
				}
				s[j] = 'B';
			}
		}
	}

	return "";
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	
	string ans = solve();
	if (ans == "") {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}

	return 0;
}
