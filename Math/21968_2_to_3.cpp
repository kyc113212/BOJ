#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>

#define MAX_V 987654321
#define MOD 1e9 + 7
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll pow_l(ll a, ll b) {
	
	ll ans = 1;
	for (int i = 0; i < b; i++) {
		ans *= a;
	}
	return ans;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		ll N;
		cin >> N;
		// 주어진 N을 2진수의 형으로 변경
		// N값의 숫자를 vector로 변경
		ll temp_v = N;
		vector<int> v;
		ll idx = 0;
		while (temp_v) {
			idx = 0;
			ll temp_ans = 1;
			int cnt = 0;
			while (1) {
				if (temp_ans > temp_v) {
					temp_ans >>= 1;
					cnt--;
					break;
				}
				else if (temp_ans == temp_v) {
					break;
				}
				temp_ans <<= 1;
				cnt++;
			}
			temp_v -= temp_ans;
			v.push_back(cnt);
		}
		ll ans = 0;
		for (int i = 0; i < v.size(); i++) {
			ans += pow_l(3, v[i]);
		}

		cout << ans << '\n';
	}

	return 0;
}
