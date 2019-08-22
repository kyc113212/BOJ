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
	else {
		for (int i = idx; i < N; i++) {
			if (!visited[i]) {
				total_sum += v[i].pay;
				visited[i] = true;
				dfs(idx + v[i].duration - 1, total_sum);
				visited[i] = false;
				total_sum -= v[i].pay;
			}
		}
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int T, P;
		cin >> T >> P;
		v.push_back(value(T, P));
	}

	for (int i = 0; i < v.size(); i++) {
		visited[i] = true;
		dfs(i + 1, v[i].pay);
		visited[i] = false;
	}

	return 0;
}
