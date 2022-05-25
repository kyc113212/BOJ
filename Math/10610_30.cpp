#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {

	string s;
	cin >> s;

	int ans = 0;
	vector<int> v;
	for (int i = 0; i < s.size(); i++) {
		v.push_back(s[i] - '0');
		ans += v[i];
	}

	sort(v.begin(), v.end(),greater<>());

	if (ans % 3 != 0 || v[v.size()-1] != 0) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
		cout << '\n';
	}

	return 0;
}
