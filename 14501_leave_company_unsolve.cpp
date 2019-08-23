#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct value {
	int duration, pay;
	value(int a, int b) : duration(a), pay(b) {}
};

int N;
int maxV = -9999;
int visited[16];
vector<value> v;

void dfs(int idx, int total_sum) {
	if (idx > N)
		return;
	else if (idx <= N) {
		maxV = max(maxV, total_sum);
	}
	for (int i = idx; i < N; i++) {
		if (!visited[i]) {
			if (i + v[i].duration <= N) {
				total_sum += v[i].pay;
				visited[i] = true;
				dfs(i + v[i].duration, total_sum);
				visited[i] = false;
				total_sum -= v[i].pay;
			}
		}
	}
	return;
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int T, P;
		cin >> T >> P;
		v.push_back(value(T, P));
	}

	if (v[0].duration == 1 && N == 1) {
		cout << v[0].pay << endl;
		return 0;
	}
	else if (N == 1 && v[0].duration > 1) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < v.size(); i++) {
		visited[i] = true;
		dfs(i + v[i].duration, v[i].pay);
		visited[i] = false;
	}

	cout << maxV << endl;

	return 0;
}
