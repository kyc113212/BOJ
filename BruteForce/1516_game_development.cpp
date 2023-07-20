#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N;
//변하지 않는값을 찾아보자
bool check_finish[502];
int finished_time[502];

bool check_all_finish() {
	for (int i = 1; i <= N; i++) {
		if (check_finish[i] == false) {
			return true;
		}
	}
	
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	deque<int> dq[502];

	for (int i = 1; i <= N; i++) {
		dq[i].push_back(i);
		while (1) {
			int a;
			cin >> a;
			if (a == -1)
				break;
			else {
				dq[i].push_back(a);
			}
		}
	}

	int cnt = 1;
	while (check_all_finish()) {

		if (check_finish[cnt] == false) {
			if (dq[cnt].size() == 2) {
				check_finish[cnt] = true;
				finished_time[cnt] = dq[cnt][1];
			}
			else {
				bool flag = false;
				int maxV = 0;
				for (int i = 2; i < dq[cnt].size(); i++) {
					if (check_finish[dq[cnt][i]] == false) {
						flag = true;
						break;
					}
					maxV = max(maxV, finished_time[dq[cnt][i]]);
				}
				if (flag == false) {
					check_finish[cnt] = true;
					finished_time[cnt] = maxV + dq[cnt][1];
				}
			}

			cnt++;
			if (cnt > N)
				cnt = 1;
		}
		else {
			cnt++;
			if (cnt > N)
				cnt = 1;
		}
		
	}

	for (int i = 1; i <= N; i++) {
		cout << finished_time[i] << '\n';
	}

	return 0;
}
