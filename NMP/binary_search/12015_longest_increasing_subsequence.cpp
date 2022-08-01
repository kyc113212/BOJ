#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> sq,rst;

void upper(int n) {
	int start = 0, end = rst.size();
	int mid;
	while (start < end) {
		mid = (end + start) / 2;
		if (rst[mid] >= n) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}
	rst[start] = n;
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		sq.push_back(a);
		if (i == 0) {
			rst.push_back(a);
		}
		else if (a > rst[rst.size() - 1]) {
			rst.push_back(a);
		}
		else {
			upper(a);
		}
	}

	cout << rst.size() << '\n';



	return 0;
}
