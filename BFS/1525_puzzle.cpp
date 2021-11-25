#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
//bool visited[1000000000];

string s;

struct info {
	string st;
	int cnt;
	info(string a, int b) : st(a), cnt(b) {}
};

int bfs() {

	queue<info> q;
	set<string> visited;

	q.push(info(s, 0));
	visited.insert(s);
	//visited[stoi(s)] = true;
	while (!q.empty()) {
		string cur_string = q.front().st;
		int cur_cnt = q.front().cnt;
		q.pop();

		if (cur_string == "123456789") {
			return cur_cnt;
		}

		int cur_idx = -1;
		for (int i = 0; i < 9; i++) {
			if (cur_string[i] == '9') {
				cur_idx = i;
				break;
			}
		}
		for (int i = 0; i < 4; i++) {
			int next_x = (cur_idx % 3) + dx[i];
			int next_y = (cur_idx / 3) + dy[i];
			if (next_x < 0 || next_y < 0 || next_x >= 3 || next_y >= 3) {
				continue;
			}
			int change_idx = next_x + next_y * 3;
			string temp_string = cur_string;
			swap(temp_string[change_idx], temp_string[cur_idx]);
			set<string>::iterator it = visited.find(temp_string);
			if (it != visited.end())
				continue;
			else {
				visited.insert(temp_string);
				q.push(info(temp_string, cur_cnt + 1));
			}
		}
	}

	return -1;
}

int main() {

	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int a;
			cin >> a;
			char b = a + '0';
			if (b == '0') {
				b = '9';
			}
			s += b;
		}
	}

	cout << bfs() << endl;
	

	return 0;
}
