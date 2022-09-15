#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

typedef long long ll;

using namespace std;

int N;
int A[4001], B[4001], C[4001], D[4001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	vector<int> ab, cd;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ab.push_back(A[i] + B[j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cd.push_back(C[i] + D[j]);
		}
	}

	sort(cd.begin(), cd.end());
	ll ans = 0;

	for (auto v : ab) {
		int diff = v * (-1);
		auto ub = upper_bound(cd.begin(), cd.end(), diff);
		auto lb = lower_bound(cd.begin(), cd.end(), diff);
		ans += (ub - lb);
	}

	cout << ans << '\n';


	return 0;
}
