// 1240

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>
#include <queue>
#include <set>

#define MAX_V 987654321
#define MOD_V 1000000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int N, r, c;
int ans = 0;

void solve(int size, int y, int x) {
	if (y == r && x == c) {
		cout << ans << '\n';
	}
	else if (y + size > r && y <= r && x + size > c && x <= c) {
		solve(size / 2, y, x);
		solve(size / 2, y, x + size / 2);
		solve(size / 2, y + size / 2, x);
		solve(size / 2, y + size / 2, x + size / 2);
	}
	else {
		ans += size * size;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;

	solve((1 << N), 0, 0);

	return 0;
}
