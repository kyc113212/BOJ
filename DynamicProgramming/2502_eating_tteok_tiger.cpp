#include <iostream>

using namespace std;

int D, K;
int arrA[32];
int arrB[32];
int ansA, ansB;

void solve() {

	for (int i = 1; i < K; i++) {
		int a = i * arrA[D];
		for (int j = i + 1; j <= K; j++) {
			if (j * arrB[D] + a == K) {
				ansA = i;
				ansB = j;
				return;
			}
		}
	}

}

int main() {

	cin >> D >> K;

	arrA[1] = 1;
	arrA[2] = 0;
	arrB[1] = 0;
	arrB[2] = 1;

	for (int i = 3; i <= D; i++) {
		arrA[i] = arrA[i - 1] + arrA[i - 2];
		arrB[i] = arrB[i - 1] + arrB[i - 2];
	}

	solve();
	cout << ansA << '\n' << ansB << '\n';


	return 0;
}
