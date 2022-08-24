#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>
#include <queue>

#define MAX_V 987654321
#define MOD 100000007
#define T_MAX_V 1000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int N, K;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	int sum = 0;
	for (int i = 1; i <= K; i++) {
		sum += i;
	}
	N -= sum;

	if (N < 0) {
		cout << -1 << '\n';
	}
	else if (N % K == 0) {
		cout << K - 1 << '\n';
	}
	else {
		cout << K << '\n';
	}

	return 0;
}
