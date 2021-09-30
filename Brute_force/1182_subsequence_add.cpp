#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
int num[21];
int cnt = 0;

void input() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
}

void dfs(int idx, int sum) {
	if (idx == N) {
		//cout << sum << endl;
		if (S == sum)
			cnt++;
		return;
	}
	dfs(idx + 1, sum);
	dfs(idx + 1, sum + num[idx]);
}

int main() {

	input();
	dfs(0, 0);

	if (S == 0)
		cnt--;
	cout << cnt << endl;

	return 0;
}
