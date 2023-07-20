//2523

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>
#include <queue>
#include <set>

#define MAX_V 987654321
#define MOD_V 1000000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int N, M;
vector<int> v;

bool check(int mid) {
	int minV = MAX_V;
	int maxV = -MAX_V;
	int cnt = 1;
	for (int i = 0; i < v.size(); i++) {
		minV = min(minV, v[i]);
		maxV = max(maxV, v[i]);
		if (mid < (maxV - minV)) {
			cnt++;
			minV = v[i];
			maxV = v[i];
		}
	}

	return cnt <= M;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < v.size(); i++) {
		cin >> v[i];
	}

	int left = 0;
	int right = *max_element(v.begin(), v.end());
	int mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (check(mid)) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << left << '\n';

	return 0;
}
