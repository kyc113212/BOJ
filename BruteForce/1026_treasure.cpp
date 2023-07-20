#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int N;
	cin >> N;
	vector<int> A, B;
	for (int j = 0; j < N; j++) {
		int temp;
		cin >> temp;
		A.push_back(temp);
	}
	for (int j = 0; j < N; j++) {
		int temp;
		cin >> temp;
		B.push_back(temp);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += (A[i] * B[i]);
	}

	cout << ans << endl;

	return 0;
}
