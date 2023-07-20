#include <iostream>
#include <algorithm>
#include <queue>
#include <algorithm>

using namespace std;

struct info {
	int s_time, n_v;
	info(int a, int b) : s_time(a), n_v(b) {}
};

struct cmp {
	bool operator()(info& a, info& b) {
		return a.s_time > b.s_time;
	}
};

int N;
int now[10005];
int finished[10005];
vector<int> graph[10005];
int work_time[10005];
int finish_time[10005];

//now가 0이고 완료되지 않은 항목을 모두 pop
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		work_time[i] = a;
		for (int j = 0; j < b; j++) {
			int c;
			cin >> c;
			graph[c].push_back(i); // time하고 다음 정보 저장
			now[i]++;
		}
	}

	priority_queue<info, vector<info>, cmp> pq;
	//pq.push(1);
	for (int i = 1; i <= N; i++) {
		if (now[i] == 0)
			pq.push(info(0,i));
	}
	int time_sum = 0;

	while (!pq.empty()) {
		int cur_w = pq.top().n_v;
		int s_time = pq.top().s_time;
		int add_time = work_time[cur_w];
		int end_time = s_time + add_time;
		pq.pop();

		if (end_time > time_sum)
			time_sum = end_time;

		for (int j = 0; j < graph[cur_w].size(); j++) {
			int next_w = graph[cur_w][j];
			finish_time[next_w] = max(finish_time[next_w], end_time);
			now[next_w]--;
			if (now[next_w] == 0) {
				pq.push(info(finish_time[next_w],next_w));
			}
		}
	}

	cout << time_sum << '\n';

	return 0;
}
