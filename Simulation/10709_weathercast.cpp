// 5522
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
#define PIE 3.14159265358979323846
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int H, W;
int cast[101][101];
int map[101][101];

void move_cloud() {
	int map2[101][101];
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			map2[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < H; i++) {
		map[i][0] = 0;
	}
	for (int i = 0; i < H; i++) {
		for (int j = 1; j < W; j++) {
			map[i][j] = map2[i][j - 1];
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < W; j++) {
			if (s[j] == 'c') {
				map[i][j] = 1;
			}
		}
	}
	memset(cast, -1, sizeof(cast));

	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				if (map[j][k] == 1 && cast[j][k] == -1) {
					cast[j][k] = i;
				}
			}
		}
		move_cloud();
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << cast[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
