//한 방향으로만 이동하므로 visited 배열이 필요 없음

#include <algorithm>
#include <iostream>
#include <deque>

struct info {
	unsigned long num, cnt;
	info(unsigned long a, unsigned long b) : num(a), cnt(b) {}
};

using namespace std;

unsigned long A, B;

int bfs() {

	deque<info> dq; 
	dq.push_back(info(A,0));

	while (!dq.empty()) {
		unsigned long c_num = dq.front().num;
		unsigned long c_cnt = dq.front().cnt;
		dq.pop_front();


		if(c_num == B){
			return c_cnt + 1;
		}

		unsigned long temp_n = c_num * 2;
		if (temp_n <= B) {
			dq.push_back(info(temp_n,c_cnt+1));
		}
		temp_n = c_num * 10 + 1;
		if (temp_n <= B) {
			dq.push_back(info(temp_n, c_cnt+1));
		}
	}

	return -1;
}

int main() {

	cin >> A >> B;

	cout << bfs() << '\n';

	return 0;
}
