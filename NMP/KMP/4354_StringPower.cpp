#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int pi[10000005];

int main() {

	while (1) {
		string s;
		int ans = 0;
		cin >> s;
		memset(pi, 0, sizeof(pi));
		if (s[0] == '.')
			break;


		int j = 0;
		for (int i = 1; i < s.size(); i++) {
			while (j > 0 && s[i] != s[j]) {
				j = pi[j - 1];
			}
			if (s[i] == s[j]) {
				pi[i] = ++j;
			}
		}

		if (s.size() % (s.size() - pi[s.size() - 1]) != 0)
			cout << 1 << '\n';
		else
			cout << s.size() / (s.size() - pi[s.size() - 1]) << '\n';
		

	}

	return 0;
}
