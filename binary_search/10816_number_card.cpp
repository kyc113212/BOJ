#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> a, b;

int upper(int n) {
	int s = 0;
	int e = N;
	while (s < e) {
		int mid = s + (e - s) / 2;
		if (a[mid] <= n) {
			s = mid + 1;
		}
		else {
			e = mid;
		}
	}
	return s;
}

int lower(int n) {
	int s = 0;
	int e = N;

	while (s < e) {
		int mid = s + (e - s) / 2;
		if (a[mid] >= n) {
			e = mid;
		}
		else {
			s = mid + 1;
		}
	}
	return s;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		b.push_back(num);
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < M; i++) {
		cout << upper(b[i]) - lower(b[i]) << ' ';
	}
	cout << '\n';

	return 0;
}
