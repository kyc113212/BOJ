#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
//변하지 않는값을 찾아보자

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<pair<int, int>> v;

	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		v.push_back(make_pair(a, i));
	}

	sort(v.begin(), v.end());
	int ans = 0;

	for (int i = 0; i < N; i++) {
		ans = max(ans, v[i].second - i);
	}

	cout << ans << endl;

	return 0;
}
