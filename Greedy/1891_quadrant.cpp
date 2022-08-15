// 1891

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

int N;
string s;
ull m_l, m_r;
ull cur_x = -1;
ull cur_y = -1;
string ans = "";

void find_point(int idx, ull size, ull y, ull x) {
	if (size == 1) {
		cur_x = x;
		cur_y = y;
		return;
	}
	else {
		if (s[idx] == '1') {
			find_point(idx + 1, size / 2, y, x);
		}
		else if (s[idx] == '2') {
			find_point(idx + 1, size / 2, y, x - size / 2);
		}
		else if (s[idx] == '3') {
			find_point(idx + 1, size / 2, y + size / 2, x - size / 2);
		}
		else if (s[idx] == '4') {
			find_point(idx + 1, size / 2, y + size / 2, x);
		}
	}
}

string go(ull size, ull y, ull x, ull r, ull c) {
	if (size == 1) {
		// size를 1로 해주지 않고 좌표로 판단시 가장 마지막 칸까지 가지않고 끝날 수 있다.
		return "";
	}
	else {
		if (y + size / 2 <= r && x + size / 2 <= c) {
			return "4" + go(size / 2, y + size/2, x + size/2, r, c);
		}
		else if (y + size / 2 <= r && x + size / 2 > c) {
			return "3" + go(size / 2, y + size/2, x, r, c);
		}
		else if (y + size / 2 > r && x + size / 2 > c) {
			return "2" + go(size / 2, y, x, r, c);
		}
		else {
			return "1" + go(size / 2, y, x + size/2, r, c);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> s;
	cin >> m_r >> m_l;

	ull size = (1ULL << N);

	find_point(0, size, 1, size);
	cur_y -= m_l;
	cur_x += m_r;

	if (cur_y > size || cur_y < 1 || cur_x > size || cur_x < 1) {
		cout << -1 << '\n';
	}
	else {
		cout << go(size, 1, 1, cur_y, cur_x) << '\n';
	}
	

	return 0;
}
