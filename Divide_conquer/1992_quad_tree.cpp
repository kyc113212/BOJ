#include <iostream>
#include <string>

using namespace std;

int N;
string ans;
int map[65][65];

bool check_rec(int y, int x, int n) {
	int map_cnt = map[y][x];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[y + i][x + j] != map_cnt)
				return false;
		}
	}
	return true;
}

void solve(int y, int x, int D, int roc) {
	if (roc == 0) {
		ans += '(';
	}
	if (check_rec(y, x, D)) {	//해당범위가 모두 같은 값일경우
		if (roc == 0) {
			ans += map[y][x] + '0';
		}
		else if (roc == 3) {
			ans += map[y][x] + '0';
			ans += ')';
		}
		else {
			ans += map[y][x] + '0';
		}
		return;
	}

	solve(y, x, D / 2, 0);
	solve(y, x+D/2, D / 2, 1);
	solve(y + D / 2, x, D / 2, 2);
	solve(y + D / 2, x + D / 2, D / 2, 3);

	if (roc == 3) {
		ans += ')';
	}
	
	//divide할때 괄호 추가
	//좌측 상단일때 (추가, 우측 하단일때 )추가
	return;
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	solve(0, 0, N, -1);
	cout << ans << '\n';

	return 0;
}
