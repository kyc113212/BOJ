#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int price[1001];
int dp[1001];

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		price[i] = a;
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + price[j]);
		}
	}

	cout << dp[N] << endl;



	return 0;
}
