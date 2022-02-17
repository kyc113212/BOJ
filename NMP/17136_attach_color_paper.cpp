#include <iostream>

using namespace std;

#define INF 987654321

int map[10][10];
int paper_cnt = 0;
int paper_specific[6] = { 0,0,0,0,0 };
int ans = INF;

bool attach_paper(int y, int x, int size) {

	if (y + size > 10 || x + size > 10)
		return false;

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (map[i][j] == 0)
				return false;
		}
	}

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			map[i][j] = 0;
		}
	}

	paper_cnt -= (size * size);

	return true;
}

void detach_paper(int y, int x, int size) {

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			map[i][j] = 1;
		}
	}

	paper_cnt += (size * size);
	return;
}

void dfs(int y, int x) {
	if (paper_cnt == 0) {
		int t_ans = 0;
		for (int i = 1; i <= 5; i++) {
			t_ans += paper_specific[i];
		}
		ans = min(ans, t_ans);
		return;
	}

	for (int i = y; i < 10; i++) {
		for (int j = x; j < 10; j++) {
			if (map[i][j] == 1) {
				for (int k = 5; k > 0; k--) {
					if (paper_specific[k] < 5 && attach_paper(i, j, k)) {
						paper_specific[k]++;
						dfs(i, j+k);
						paper_specific[k]--;
						detach_paper(i, j, k);
					}
				}
				return;
			}
		}
		x = 0;
	}
	//for문 내부에서 return을 어디다 해야할까
	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j])
				paper_cnt++;
		}
	}

	dfs(0, 0);

	if (ans != INF)
		cout << ans << '\n';
	else
		cout << -1 << '\n';

	return 0;
}
