#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> a, b;

int sol(int n) {
	int start = 0;
	int end = N - 1;
	if (n == a[start] || n == a[end]) {
		return 1;
	}
	int mid = (start + end) / 2;

	while (start <= end) {

		if (a[mid] == n)
			return 1;
		else if (a[mid] > n) {
			end = mid - 1;
		}
		else if (a[mid] < n) {
			start = mid + 1;
		}

		mid = (start + end) / 2;

	}

	return 0;
}

int main() {

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}
	sort(a.begin(), a.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		b.push_back(num);
	}

	for (int i = 0; i < M; i++) {
		cout << sol(b[i]) << '\n';
	}

	return 0;
}
