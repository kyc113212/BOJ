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

int N, L, R, X;
vector<int> v;
vector<int> ans;
int cnt = 0;

void dfs(int idx, int sum) {
	if (idx == N+1)
		return;
	if (ans.size() >= 2 && ans[ans.size() - 1] - ans[0] >= X && sum >= L && sum <= R) {
		cnt++;
	}
	for (int i = idx; i < v.size(); i++) {
		ans.push_back(v[i]);
		dfs(i + 1, sum + v[i]);
		ans.pop_back();
	}

	return;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R >> X;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		ans.push_back(v[i]);
		dfs(i + 1, v[i]);
		ans.pop_back();
	}
	cout << cnt << '\n';
	return 0;
}
