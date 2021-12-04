//10818 백준

#include <iostream>
#include <string>

using namespace std;

int arr[200005];
string A, B, C;

void make_fail_func() {
	int j = 0;
	for (int i = 1; i < C.size(); i++) {
		while (j > 0 && C[i] != C[j]) {
			j = arr[j - 1];
		}
		if (C[i] == C[j]) {
			arr[i] = ++j;
		}
	}
}

int main() {

	cin >> A >> B >> C;
	make_fail_func();
	int j = 0;
	int ans = 0;
	for (int i = 0; i < A.size(); i++) {
		while (j > 0 && A[i] != C[j]) {
			j = arr[j - 1];
		}
		if (A[i] == C[j]) {
			j++;
			if (j == C.size()) {
				ans = 1;
				break;
			}
		}
	}

	if (ans)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	return 0;
}
