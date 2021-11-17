#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
	int st, ed;
	info(int a, int b) : st(a), ed(b) {}
};

bool cmp(info &a, info &b) {
	if (a.ed == b.ed) {
		return a.st < b.st;
	}
	else
		return a.ed < b.ed;
}

int N;
int cnt;

int main() {
	
	cin >> N;
	vector<info> v;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(info(a, b));
	}

	sort(v.begin(), v.end(), cmp);

	//cnt = 1;
	//int cur_end = v[0].ed - 1;
	int cur_end = -1;
	for (int i = 0; i < v.size(); i++) {
		if (cur_end >= v[i].st) {
			continue;
		}
		else {
			cur_end = v[i].ed - 1;
			cnt++;
			
		}
	}

	cout << cnt << '\n';

	return 0;
}
