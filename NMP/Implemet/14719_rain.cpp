#include <iostream>
#include <algorithm>

using namespace std;

int W, H;
int map[505];

int solve() {
	
	int ans = 0;

	for (int i = 0; i < W; i++) {
		bool check_left = false;
		bool check_right = false;
		bool final_check = false;
		int max_left = 0;
		int max_right = 0;
		for (int j = 0; j < i; j++) {
			if (map[i] < map[j]) {
				max_left = max(max_left,map[j]);
			}
		}
		for (int j = i+1; j < W; j++) {
			if (map[i] < map[j]) {
				max_right = max(max_right, map[j]);
			}
		}
		if (max_right > 0 && max_left > 0) {
			if (max_right > max_left) {
				ans += (max_left - map[i]);
			}
			else {
				ans += (max_right - map[i]);
			}
		}
	}

	return ans;
}

int main() {

	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		cin >> map[i];
	}

	cout << solve() << '\n';
	

	return 0;
}
