// 17069
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

vector<int> origin;
vector<int> compare;
int ans = MAX_V;
bool visited[10];

bool check() {
	
	if (compare[0] + compare[1] + compare[2] != 15)
		return false;
	if (compare[3] + compare[4] + compare[5] != 15)
		return false;
	if (compare[6] + compare[7] + compare[8] != 15)
		return false;
	if (compare[0] + compare[3] + compare[6] != 15)
		return false;
	if (compare[1] + compare[4] + compare[7] != 15)
		return false;
	if (compare[2] + compare[5] + compare[8] != 15)
		return false;
	if (compare[0] + compare[4] + compare[8] != 15)
		return false;
	if (compare[2] + compare[4] + compare[6] != 15)
		return false;

	return true;
}

void dfs(int cnt) {
	if (cnt == 9) {
		if (check()) {
			int temp = 0;
			for (int i = 0; i < 9; i++) {
				temp += abs(origin[i] - compare[i]);
			}
			ans = min(ans, temp);
		}
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		compare.push_back(i);
		dfs(cnt + 1);
		compare.pop_back();
		visited[i] = false;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		int a;
		cin >> a;
		origin.push_back(a);
	}

	dfs(0);

	cout << ans << '\n';

	return 0;
}
