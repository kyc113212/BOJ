#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N;
int visited[11] = {};
int people_cnt[11] = {};
int map[11][11] = {};
int check[11] = {};
int cnt_check = 0;
int ans = 9999;

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

	if (visited[0] == 0 && visited[2] == 0 && visited[3] == 0 && visited[7] == 0) {
		if (visited[1] == 1 && visited[4] == 1 && visited[5] == 1 && visited[6] == 1) {

			int a;
			a = 0;
		}
	}

	while (check_group() == true) {
		for (int i = 0; i < N; i++) {
			if (check[i] == 0) {
				int cur_group = visited[i];
				if (cur_group == 0) {
					labeling++;
					check[i] = labeling;
					group1.push(i);
					while (!group1.empty()) {
						int cur_idx = group1.front();
						group1.pop();
						for (int j = 0; j < N; j++) {
							if (cur_idx == j)
								continue;
							if (visited[j] == cur_group && check[j] == 0 && map[cur_idx][j] == 1) {
								group1.push(j);
								check[j] = labeling;
							}
						}
					}
				}
				if (cur_group == 1) {
					labeling++;
					check[i] = labeling;
					group2.push(i);
					while (!group2.empty()) {
						int cur_idx = group2.front();
						group2.pop();
						for (int j = 0; j < N; j++) {
							if (cur_idx == j)
								continue;
							if (visited[j] == cur_group && check[j] == 0 && map[cur_idx][j] == 1) {
								group2.push(j);
								check[j] = labeling;
							}
						}
					}
				}
			}
		}
	}



	if (labeling == 2) {
		int sumA = 0;
		int sumB = 0;
		for (int i = 0; i < N; i++) {
			if (visited[i] == 1) {
				sumA += people_cnt[i];
			}
			else {
				sumB += people_cnt[i];
			}
		}

		ans = min(ans, abs(sumA - sumB));

	}


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

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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
			map[i][b-1] = 1;
			//map[b-1][i] = 1;
		}
	}


	vector<int> v;
	v.push_back(0);
	divide_space(0, v);
	v.pop_back();

	if (ans == 9999) {
		cout << -1 << endl;
	}
	else
		cout << ans << endl;;

	return 0;
}
