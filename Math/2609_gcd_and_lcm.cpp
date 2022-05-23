#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A, B;

int gcd(int a, int b) {
	if (a < b) {
		swap(a, b);
	}
	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {

	cin >> A >> B;

	cout << gcd(A, B) << '\n' << lcm(A, B) << '\n';

	return 0;
}
