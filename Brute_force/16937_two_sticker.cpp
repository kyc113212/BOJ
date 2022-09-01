#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>
#include <queue>

#define MAX_V 987654321
#define MOD_V 1000000007
#define T_MAX_V 1000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct info {
	int r, c;
	info(int r, int c) : r(r), c(c) {}
};

bool cmp(info &a, info &b) {
	return a.c*a.r > b.c*b.r;
}

vector<info> v;
int H, W;
int N;
int max_ans = 0;

int calc(int a, int b) {
	//4가지의 경우의 수를 모두 계산
	int ans = 0;
	for (int i = 0; i < 4; i++) {

		// 비회전 비회전
		if (i == 0) {
			if (v[a].r + v[b].r <= H && max(v[a].c, v[b].c) <= W) {
				ans = v[a].r * v[a].c + v[b].r * v[b].c;
				return ans;
			}
			if (v[a].c + v[b].c <= W && max(v[a].r, v[b].r) <= H) {
				ans = v[a].r * v[a].c + v[b].r * v[b].c;
				return ans;
			}
		}
		// 회전 비회전
		else if (i == 1) {
			if (v[a].c + v[b].r <= H && max(v[a].r, v[b].c) <= W) {
				ans = v[a].r * v[a].c + v[b].r * v[b].c;
				return ans;
			}
			if (v[a].r + v[b].c <= W && max(v[a].c, v[b].r) <= H) {
				ans = v[a].r * v[a].c + v[b].r * v[b].c;
				return ans;
			}
		}
		// 비회전 회전
		else if (i == 2) {
			if (v[a].r + v[b].c <= H && max(v[a].c, v[b].r) <= W) {
				ans = v[a].r * v[a].c + v[b].r * v[b].c;
				return ans;
			}
			if (v[a].c + v[b].r <= W && max(v[a].r, v[b].c) <= H) {
				ans = v[a].r * v[a].c + v[b].r * v[b].c;
				return ans;
			}
		}
		// 회전 회전
		else if (i == 3) {
			if (v[a].c + v[b].c <= H && max(v[a].r, v[b].r) <= W) {
				ans = v[a].r * v[a].c + v[b].r * v[b].c;
				return ans;
			}
			if (v[a].r + v[b].r <= W && max(v[a].c, v[b].c) <= H) {
				ans = v[a].r * v[a].c + v[b].r * v[b].c;
				return ans;
			}
		}
	}
	return 0;
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int temp = calc(i, j);
			max_ans = max(temp, max_ans);
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >> W;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int r, c;
		cin >> r >> c;
		v.push_back(info(r, c));
	}
	sort(v.begin(), v.end(), cmp);

	solve();
	cout << max_ans << '\n';

	return 0;
}
