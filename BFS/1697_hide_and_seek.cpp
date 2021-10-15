#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct info {

	int num, cnt;
	info(int a, int b) : num(a), cnt(b) {}
};
	
int startN, targetN;
int ans;
bool visited[100001];

void bfs() {

	queue<info> q;
	q.push(info(startN,0));
	visited[startN] = true;

	while (!q.empty()) {

		int c_num = q.front().num;
		int c_cnt = q.front().cnt;
		
		q.pop();

		if (c_num == targetN) {
			ans = c_cnt;
			return;
		}

		for (int i = 0; i < 3; i++) {

			int temp_num = 0;

			if (i == 0) {
				temp_num = c_num - 1;
			}
			else if (i == 1) {
				temp_num = c_num + 1;
			}
			else {
				temp_num = c_num * 2;
			}

			if (temp_num < 0)
				continue;
			if (temp_num > 100000)
				continue;
			if (visited[temp_num])
				continue;
			visited[temp_num] = true;
			
			q.push(info(temp_num, c_cnt + 1));

		}




	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false);

	cin >> startN >> targetN;

	bfs();

	cout << ans << endl;


	return 0;
}
