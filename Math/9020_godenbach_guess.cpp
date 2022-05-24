#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool check[10001];
int N;

int main() {

	cin >> N;
	check[1] = true;
	for (int i = 2; i <= sqrt(10000); i++) {
		for (int j = i * 2; j <= 10000; j += i) {
			check[j] = true;
		}
	}
	while (N--) {

		int M;
		cin >> M;
		int temp_M = M / 2;
		for (int i = temp_M; i >= 1; i--) {
			if (!check[i] && !check[M - i]) {
				cout << i << ' ' << M - i << '\n';
				break;
			}
		}
	}
	
	return 0;
}
