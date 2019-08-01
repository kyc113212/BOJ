#include <iostream>
#include <vector>

using namespace std;

int H, N;
int top[500002];
int bottom[500002];
int top_total[500002];
int bottom_total[500002];
int total[500002];
int minV = 99999;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> H;
	int cnt = 1;

	for (int i = 0; i < N/2; i++) {
		int t_top, t_bottom;
		cin >> t_bottom >> t_top;
		bottom[t_bottom]++;
		top[t_top]++;
	}

	for (int i = H; i >= 1; i--) {
		bottom_total[i] = bottom[i] + bottom_total[i + 1];
		top_total[i] = top[i] + top_total[i + 1];
	}

	for (int i = 1; i <= H; i++) {
		total[i] = bottom_total[i] + top_total[H - i + 1];
		if (total[i] <= minV) {
			if (total[i] == minV) {
				cnt++;
			}
			else {
				minV = total[i];
				cnt = 1;
			}
		}
	}

	cout << minV << " " << cnt << endl;

	return 0;
}
