#include <iostream>
#include <string>

using namespace std;

string A, B;
int check_fail[200001];

void make_fail() {

	int j = 0;
	for (int i = 1; i < B.size(); i++) {
		if (j > 0 && B[i] != B[j]) {
			j = check_fail[j - 1];
		}
		if (B[i] == B[j]) {
			check_fail[i] = ++j;
		}
	}

}

int main() {

	cin >> A >> B;
	make_fail();

	int ans = 0;
	int j = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] >= 48 && A[i] <= 57) {
			continue;
		}
		if (j > 0 && B[j] != A[i]) {
			j = check_fail[j - 1];
		}
		if (A[i] == B[j]) {
			j++;
			if (j == B.size()) {
				j = 0;
				ans++;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
