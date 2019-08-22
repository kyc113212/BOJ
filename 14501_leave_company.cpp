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
	else if(idx < N) {
		maxV = max(maxV, total_sum);
	}
	for (int i = idx; i < N; i++) {
		if (!visited[i]) {
			if (idx + v[i].duration < N) {
				total_sum += v[i].pay;
				visited[i] = true;
				dfs(idx + v[i].duration, total_sum);
				visited[i] = false;
				total_sum -= v[i].pay;
			}
			else
				return;			
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

	for (int i = 0; i < v.size(); i++) {
		visited[i] = true;
		dfs(i + v[i].duration, v[i].pay);
		visited[i] = false;
	}

	//if(v[v.size()-1].duration == 1 )

	cout << maxV << endl;

	return 0;
}
