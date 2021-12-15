#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N, P;
int arr[1000001];

int main() {

	cin >> N >> P;
	vector<int> rst;
	rst.push_back(N);
	arr[N] = 1;

	int ans = 0;

	while (1) {
		int temp_n = N;
		vector<int> temp_v;
		while (temp_n) {
			temp_v.push_back(temp_n % 10);
			temp_n /= 10;
		}
		for (int i = 0; i < temp_v.size(); i++) {
			ans += pow(temp_v[i], P);
		}
		if (arr[ans]) {
			break;
		}
		arr[ans] = 1;
		rst.push_back(ans);
		N = ans;
		ans = 0;
	}

	int ans_idx = 0;
	for (int i = 0; i < rst.size(); i++) {
		if (ans == rst[i]) {
			ans_idx = i;
			break;
		}
	}

	cout << ans_idx << '\n';


	return 0;
}
