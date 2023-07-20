#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>
#include <queue>

#define MAX_V 987654321
#define MOD_V 1000000007
#define T_MAX_V 1000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int N;
vector<int> ans;

void check_valid(int value) {
	int left = 0;
	int right = ans.size() - 1;
	int ans_index = 0;
	int mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (ans[mid] < value) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			ans_index = mid;
		}
	}
	ans[ans_index] = value;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int> v;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	ans.push_back(v[0]);
	for (int i = 1; i < N; i++) {
		if (ans.back() > v[i]) {
			// lower bounder에서 변경
			// index값 변경
			check_valid(v[i]);
		}
		else {
			ans.push_back(v[i]);
		}
	}

	cout << v.size() - ans.size() << '\n';

	return 0;
}
