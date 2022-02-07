#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<int> v;

bool check_bad(int num) {
	for (int i = 1; i <= v.size() / 2; i++) {
		int temp_i = v.size() - 1;
		bool check = false;
		int v_size = v.size();
		for (int j = v_size - i - 1; j > v_size - (i * 2) - 1; j--) {
			if (v[temp_i] != v[j]) {
				check = true;
			}
			temp_i--;
		}
		if (check == false) {
			return false;
		}
	}

	return true;
}

bool dfs(int idx) {
	if (idx == N) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
		cout << '\n';
		return true;
	}
	for (int i = 1; i <= 3; i++) {
		if (i == v[idx - 1])
			continue;

		v.push_back(i);
		if (check_bad(i)) {
			if (dfs(idx + 1)) {
				return true;
			}
		}
		v.pop_back();
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	v.push_back(1);
	dfs(1);

	return 0;
}
