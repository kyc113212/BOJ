#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int visited[100001];

int N, T, G;

struct info {
	int num, cnt;
	info(int a, int b) : num(a), cnt(b) {}
};

int bfs() {

	queue<info> q;
	q.push(info(N, 0));
	visited[N] = 1;
	while (!q.empty()) {
		int c_num = q.front().num;
		int c_cnt = q.front().cnt;

		q.pop();
		if (c_cnt > T)
			continue;
		if (c_num == G) 
			return c_cnt;

		if (c_num <= 99999 && visited[c_num+1] == 0) {
			visited[c_num + 1] = 1;
			q.push(info(c_num+1, c_cnt+1));
		}

		int temp_num = c_num * 2;
		if (temp_num > 99999)
			continue;
		int ja_cnt = 0;
		int mod_num = 0;
		while (temp_num != 0) {
			int t_n = temp_num / 10;
			if (t_n == 0) {
				break;
			}
			else {
				temp_num /= 10;
				ja_cnt++;
			}
		}
		int n_num = c_num * 2 - pow(10, ja_cnt);

		if (n_num > 0 && n_num <= 99999 && visited[n_num] == 0) {
			visited[n_num] = 1;
			q.push(info(n_num, c_cnt + 1));
		}

	}
	return -1;
}

int main() {

	cin >> N >> T >> G;
	int ans = bfs();
	if (ans == -1) {
		cout << "ANG" << '\n';
	}
	else
		cout << ans << '\n';
	

	return 0;
}
