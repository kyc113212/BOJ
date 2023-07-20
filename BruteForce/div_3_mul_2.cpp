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

bool visited[101];
int N;
vector<ll> v;
vector<ll> ans;

bool dfs(int cnt) {
	if (cnt == N) {
		for (int i = 0; i < v.size(); i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return true;
	}
	for (int i = 0; i < N; i++) {
		if (cnt == 0) {
			ans.push_back(v[i]);
			visited[i] = true;
			if (dfs(cnt + 1))
				return true;
			visited[i] = false;
			ans.pop_back();
		}
		else {
			if (visited[i])
				continue;
			if (v[i] == ans[ans.size() - 1] * 2 || (v[i] == ans[ans.size() - 1] / 3 && ans[ans.size()-1] % 3 == 0)) {
				visited[i] = true;
				ans.push_back(v[i]);
				if (dfs(cnt + 1))
					return true;
				visited[i] = false;
				ans.pop_back();
			}
		}
	}

	return false;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	dfs(0);


	return 0;
}
