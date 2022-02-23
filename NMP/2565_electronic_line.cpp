#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
	int st, ed;
	info(int a, int b) : st(a), ed(b) {}
};

bool cmp(info& a, info& b) {
	return a.st < b.st;
}

int N;
int DP[501];

int main() {

	ios_base::sync_with_stdio(false);
	cin >> N;
	vector<info> v;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(info(a, b));
	}

	sort(v.begin(), v.end(), cmp);

	DP[0] = 1;
	for (int i = 0; i < N; i++) {
		if (DP[i] < 1)
			DP[i] = 1;
		for (int j = i + 1; j < N; j++) {
			if ((DP[j] < DP[i] + 1) && v[i].ed < v[j].ed) {
				DP[j] = DP[i] + 1;
			}
		}
	}

	int maxV = 0;
	for (int i = 0; i < N; i++) {
		maxV = max(maxV, DP[i]);
	}

	cout << N - maxV << '\n';

	return 0;
}
