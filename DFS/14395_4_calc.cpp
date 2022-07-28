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

struct info {
	ll num;
	string s;
	info(ll n, string s) : num(n), s(s) {}
};

int s, t;

string ans() {

	if (s == t) {
		return "0";
	}

	queue<info> q;
	q.push(info(s, ""));
	bool check_one = false;

	while (!q.empty()) {
		ll num = q.front().num;
		string s = q.front().s;
		q.pop();

		if (num == t) {
			return s;
		}

		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				if (num*num > t) {
					continue;
				}
				if (num == 1) {
					continue;
				}
				q.push(info(num*num, s + "*"));
			}
			else if (i == 1) {
				if (num + num > t) {
					continue;
				}
				q.push(info(num+num, s + "+"));
			}
			else if (i == 2) {
				if (num == 1) {
					continue;
				}
				if (check_one) {
					continue;
				}
				else {
					check_one = true;
					q.push(info(1, s + "/"));
				}
			}
		}
	}

	return "a";
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s >> t;

	if (ans() == "a") {
		cout << -1 << '\n';
	}
	else {
		cout << ans() << '\n';
	}

	return 0;
}
