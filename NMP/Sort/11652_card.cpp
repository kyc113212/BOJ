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

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<ll> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		ll a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	ll ans = v[0];
	ll maxV = 1;
	ll cnt = 1;
	for (int i = 1; i < N; i++) {
		if (v[i] == v[i - 1]) {
			cnt++;
		}
		else {
			cnt = 1;
		}
		if (maxV < cnt) {
			ans = v[i];
			maxV = cnt;
		}
	}

	cout << ans << '\n';

	return 0;
}
