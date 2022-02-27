#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define MAX_V 542
long long K, N;

int main() {

	cin >> K >> N;
	vector<long long> v;
	map<long long, int> m;
	priority_queue<long long, vector<long long>, greater<>> pq;
	pq.push(1);
	m[1] = 1;
	long long max_value = 0;

	for (int i = 0; i < K; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	
	while (N--) {
		long long cur_num = pq.top();
		pq.pop();
		for (int i = 0; i < v.size(); i++) {
			long long next_v = v[i] * cur_num;
			if (m.count(next_v))
				continue;

			if (pq.size() > N) {
				if (next_v >= max_value) {
					continue;
				}
			}

			max_value = max(max_value, next_v);
			m.insert(make_pair(next_v, 1));
			pq.push(next_v);
		}
	}

	cout << pq.top() << '\n';

	return 0;
}
