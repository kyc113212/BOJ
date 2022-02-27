#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct loc {
	int from, cnt;
	loc(int b, int c) : from(b), cnt(c) {}
};

vector<int> path;
bool visited[100005];
int parent[100005];
int N, K;

int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> N >> K;

	queue<loc> q;
	q.push(loc(N, 0));
	visited[N] = true;

	while (!q.empty()) {
		int cur_loc = q.front().from;
		int cur_cnt = q.front().cnt;
		q.pop();

		if (cur_loc == K) {
			int p = cur_loc;
			while (p != N) {
				path.push_back(p);
				p = parent[p];
			}
			path.push_back(N);
			break;
		}

		for (int i = 0; i < 3; i++) {
			int temp_loc = 0;
			if (i == 0) {
				temp_loc = cur_loc - 1;
				if (temp_loc < 0)
					continue;
				if (visited[temp_loc])
					continue;
				visited[temp_loc] = true;
				parent[temp_loc] = cur_loc;
				q.push(loc(temp_loc, cur_cnt + 1));
			}
			else if (i == 1) {
				temp_loc = cur_loc + 1;
				if (temp_loc > 100000)
					continue;
				if (temp_loc > 2 * K)
					continue;
				if (visited[temp_loc])
					continue;
				visited[temp_loc] = true;
				parent[temp_loc] = cur_loc;
				q.push(loc(temp_loc, cur_cnt + 1));
			}
			else if (i == 2) {
				temp_loc = cur_loc * 2;
				if (temp_loc > 100000)
					continue;
				if (temp_loc > 2 * K)
					continue;
				if (visited[temp_loc])
					continue;
				visited[temp_loc] = true;
				parent[temp_loc] = cur_loc;
				q.push(loc(temp_loc, cur_cnt + 1));
			}
		}	

	}

	cout << path.size() - 1 << '\n';
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << ' ';
	}
	cout << '\n';

	return 0;
}
