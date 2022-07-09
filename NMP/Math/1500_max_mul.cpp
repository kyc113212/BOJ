#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>

#define MAX_V 987654321
#define MOD 100000009
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<ll> v;
	int S, K;
	cin >> S >> K;
	int div_num = S / K;
	int mod_num = S % K;
	ll ans = 1;

	for (int i = 0; i < mod_num; i++) {
		ans *= (div_num + 1);
	}
	for (int i = 0; i < K - mod_num; i++) {
		ans *= (div_num);
	}

	cout << ans << '\n';

	return 0;
}
