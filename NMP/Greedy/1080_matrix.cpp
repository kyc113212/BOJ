// 1193

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>

#define MAX_V 98765432100
#define MOD 100000009
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int map[51][51];
int c_map[51][51];

void change_map(int y, int x) {
	for (int i = y; i < y + 3; i++) {
		for (int j = x; j < x + 3; j++) {
			c_map[i][j] = 1 - c_map[i][j];
		}
	}
}

int main() {

	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int R, C;
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '1') {
				map[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '1') {
				c_map[i][j] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < R - 2; i++) {
		for (int j = 0; j < C - 2; j++) {
			if (map[i][j] != c_map[i][j]) {
				change_map(i, j);
				cnt++;
			}
		}
	}

	bool check = false;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != c_map[i][j]) {
				check = true;
			}
		}
	}

	if (check)
		cout << -1 << '\n';
	else
		cout << cnt << '\n';
	


	return 0;
}
