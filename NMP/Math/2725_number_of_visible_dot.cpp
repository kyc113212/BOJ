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

int arr[1001];

int gcd(int a, int b) {
	while (b) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 1; i <= 1000; i++) {
		int ans = 0;
		for (int j = 0; j <= i; j++) {
			if (gcd(i, j) == 1) {
				ans++;
			}
		}
		arr[i] = arr[i-1] + ans;
	}

	while (T--) {
		int N;
		cin >> N;
		cout << arr[N] * 2 - 1 << '\n';
	}
	


	return 0;
}
