#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;

struct info {
	int num;
	string s;
	info(int a, string b) : num(a), s(b) {}
};

int N;
int visited[10001];

string bfs(int a, int b) {

	memset(visited, 0, sizeof(visited));
	queue<info> q;
	visited[a] = 1;
	q.push(info(a, ""));

	while (!q.empty()) {
		int c_num = q.front().num;
		string c_string = q.front().s;
		q.pop();
		
		if (c_num == b) {
			return c_string;
		}

		int d_num = (c_num * 2) % 10000;
		if (visited[d_num] == 0) {
			visited[d_num] = 1;
			q.push(info(d_num, c_string + "D"));
		}

		int s_num = c_num - 1;
		if (c_num == 0)
			s_num = 9999;
		if (visited[s_num] == 0) {
			visited[s_num] = 1;
			q.push(info(s_num, c_string + "S"));
		}
		
		int l_num = (c_num % 1000) * 10 + c_num / 1000;
		if (visited[l_num] == 0) {
			visited[l_num] = 1;
			q.push(info(l_num, c_string + "L"));
		}

		int r_num = (c_num % 10) * 1000 + (c_num / 10);
		if (visited[r_num] == 0) {
			visited[r_num] = 1;
			q.push(info(r_num, c_string + "R"));
		}

	}


	return NULL;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<string> rr;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		string rst;

		rst = bfs(a, b);
		rr.push_back(rst);
	}

	for (int i = 0; i < rr.size(); i++) {
		cout << rr[i] << '\n';
	}


	return 0;
}
