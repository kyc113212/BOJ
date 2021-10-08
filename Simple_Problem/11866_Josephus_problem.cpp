#include <iostream>
#include <deque>

using namespace std;

int N, K;
int visited[1001];

int main() {

	cin >> N >> K;
	deque<int> dq;
	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	deque<int> rst;

	int cnt = 1;

	while (1) {
		if (dq.size() == 1) {
			rst.push_back(dq[0]);
			break;
		}

		if (cnt % K == 0) {
			rst.push_back(dq.front());
			dq.pop_front();
			cnt = 1;
		}
		else {
			dq.push_back(dq.front());
			dq.pop_front();
			cnt++;
		}
	}

	cout << "<";
	for (int i = 0; i < rst.size() - 1; i++) {
		cout << rst[i] << ", ";
	}
	cout << rst[rst.size() - 1] << ">" << endl;

	return 0;
}
