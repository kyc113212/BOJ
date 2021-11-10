#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int N, L;
vector<int> v;

int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> L;
	deque<pair<int,int>> dq;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < N; i++) {
		if (!dq.empty() && dq.front().second <= i - L) {
			dq.pop_front();
		}
		while (!dq.empty() && dq.back().first > v[i]) {
			dq.pop_back();
		}
		dq.push_back(make_pair(v[i], i));
		cout << dq.front().first << " ";
	}

	cout << '\n';

	return 0;
}
