#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>
#include <queue>

#define MAX_V 987654321
#define MOD 100000007
#define T_MAX_V 1000000000
#define TREE_HEIGHT 20
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

vector<int> bag;
vector<pair<int, int>> jewel;
int N, K;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int m, v;
		cin >> m >> v;
		jewel.push_back(make_pair(m, v));
	}
	bag.resize(K);
	for (int i = 0; i < K; i++) {
		cin >> bag[i];
	}

	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());

	priority_queue<int, vector<int>> pq;
	ll ans = 0;
	for (int i = 0, j = 0; i < K; i++) {
		while (j < N && bag[i] >= jewel[j].first) {
			pq.push(jewel[j++].second);
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	
	cout << ans << '\n';

	return 0;
}
