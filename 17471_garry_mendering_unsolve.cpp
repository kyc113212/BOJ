#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N;
int visited[11];
int people_cnt[11];
int map[11][11];
int check[11];
int cnt_check = 0;

bool check_group() {
	for (int i = 0; i < N; i++) {
		if (check[i] == 0) {
			return true;
		}
	}
	return false;
}

void solve(vector<int> &tv) {
	memset(visited, 0, sizeof(visited));
	memset(check, 0, sizeof(check));
	for (int i = 0; i < N; i++) {
		visited[i] = tv[i];
	}

	queue<int> group1, group2;
	int labeling = 0;

	while (check_group() == true) {
		for (int i = 0; i < N; i++) {
			if (check[i] == 0) {
				check[i] = 1;
				labeling++;
				int cur_group = visited[i];
				if (cur_group == 0) {
					group1.push(i);
					while (!group1.empty()) {
						int cur_idx = group1.front();
						group1.pop();
						for (int j = 0; j < N; j++) {
							if (visited[j] == cur_group && check[j] == 0 && map[cur_idx][j] == 1) {
								group1.push(j);
								check[j] = 1;
							}
						}
					}					
				}
				else if (cur_group == 1) {
					group2.push(i);
					while (!group2.empty()) {
						int cur_idx = group2.front();
						group2.pop();
						for (int j = 0; j < N; j++) {
							if (visited[j] == cur_group && check[j] == 0 && map[i][j] == 1) {
								group2.push(j);
								check[j] = 1;
							}
						}
					}
				}
			}
		}
	}

	int a;
	a = 0;

	return;
}

void divide_space(int cnt, vector<int> &tv) {
	if (tv.size() == N) {
		solve(tv);
		cnt_check++;
		return;
	}
	for (int i = cnt + 1; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			tv.push_back(j);
			divide_space(i, tv);
			tv.pop_back();
		}
	}

	return;
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> people_cnt[i];
	}
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			map[i][b] = 1;
			map[b][i] = 1;
		}
	}


	vector<int> v;
	for (int i = 0; i < 2; i++) {
		v.push_back(i);
		divide_space(0, v);
		v.pop_back();
	}

	cout << cnt_check << endl;;

	return 0;
}
