#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, L;
	bool check[1001] = { false, };
	cin >> N >> L;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (check[i] == false) {
			check[i] = true;
			cnt++;
			for (int j = i + 1; j < v.size(); j++) {
				if (v[i] + L > v[j]) {
					check[j] = true;
				}
			}
		}
	}

	cout << cnt << endl;

	return 0;
}
