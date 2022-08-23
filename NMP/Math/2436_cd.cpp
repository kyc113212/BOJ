//2523

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

int gcd(int a, int b) {
	while (b) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int gc, lm;
	cin >> gc >> lm;

	int div = lm / gc;
	int ra = 0;
	int rb = 0;
	for (int i = 1; i <= sqrt(div); i++) {
		if (div % i == 0) {
			int rst = gcd(div/i, i);
			if (rst == 1) {
				ra = i;
				rb = div/i;
			}
		}
	}

	cout << ra * gc << ' ' << rb * gc << '\n';


	return 0;
}
