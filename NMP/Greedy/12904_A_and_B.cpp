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

string S, T;
deque<char> dq;

int solve() {

	while (1) {
		if (S.size() == dq.size()) {
			//비교
			for (int i = 0; i < dq.size(); i++) {
				if (dq[i] != S[i]) {
					return 0;
				}
			}
			return 1;
		}
		if (dq.back() == 'A') {
			dq.pop_back();
		}
		else {
			dq.pop_back();
			reverse(dq.begin(), dq.end());
		}
	}

	return 0;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> S >> T;
	for (int i = 0; i < T.size(); i++) {
		dq.push_back(T[i]);
	}

	cout << solve() << '\n';
	

	return 0;
}
