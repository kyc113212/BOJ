#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {

	int N;
	cin >> N;
	while (N--) {
		int cnt;
		cin >> cnt;
		vector<int> v;
		v.resize(cnt);
		ll ans = 0;
		for (int i = 0; i < cnt; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < cnt-1; i++) {
			for (int j = i + 1; j < cnt; j++) {
				ans += gcd(v[i], v[j]);
			}
		}
		cout << ans << '\n';
	}
	
	
	return 0;
}
