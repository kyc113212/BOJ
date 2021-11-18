#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct info {
	int st, ed;
	info(int a, int b) : st(a), ed(b) {}
};

bool cmp(info& a, info& b) {
	if (a.st == b.st)
		return a.ed < b.ed;
	else
		return a.st < b.st;
}

int N;
vector<info> v;
vector<int> room_endtime;
priority_queue<int, vector<int>, greater<>> pq;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(info(a, b));
	}

	sort(v.begin(), v.end(), cmp);

	int cnt = 1;
	pq.push(v[0].ed);

	for (int i = 1; i < v.size(); i++) {
		if (pq.top() > v[i].st) {
			cnt++;
			pq.push(v[i].ed);
		}
		else if (pq.top() <= v[i].st) {
			pq.pop();
			pq.push(v[i].ed);
		}
	}

	cout << cnt << '\n';

	return 0;
}
