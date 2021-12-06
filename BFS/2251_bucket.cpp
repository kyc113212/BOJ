#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> rst;
int visited[202][202][202];
int f_visited[202];

struct info {
	int w1, w2, w3;
	info(int a, int b, int c) : w1(a), w2(b), w3(c) {}
};

int A, B, C;

void bfs() {

	queue<info> q;
	q.push(info(0, 0, C));

	while (!q.empty()) {
		int a1 = q.front().w1;
		int a2 = q.front().w2;
		int a3 = q.front().w3;
		q.pop();

		if (f_visited[a3] == 0 && a1 == 0) {
			rst.push_back(a3);
			f_visited[a3] = 1;
		}

		//a->b
		if (a1 + a2 > B) {
			int t1 = a1 + a2 - B;
			int t2 = B;
			if (visited[t1][t2][a3] == 0) {
				visited[t1][t2][a3] = 1;
				q.push(info(t1, t2, a3));
			}
		}
		else if (a1 + a2 <= B){
			int t1 = 0;
			int t2 = a1 + a2;
			if (visited[t1][t2][a3] == 0) {
				visited[t1][t2][a3] = 1;
				q.push(info(t1, t2, a3));
			}
		}
		//a->c
		if (a1 + a3 > C) {
			int t1 = a1 + a3 - C;
			int t3 = C;
			if (visited[t1][a2][t3] == 0) {
				visited[t1][a2][t3] = 1;
				q.push(info(t1, a2, t3));
			}
		}
		else if (a1 + a3 <= C) {
			int t1 = 0;
			int t3 = a1 + a3;
			if (visited[t1][a2][t3] == 0) {
				visited[t1][a2][t3] = 1;
				q.push(info(t1, a2, t3));
			}
		}

		//b->c
		if (a2 + a3 > C) {
			int t2 = a2 + a3 - C;
			int t3 = C;
			if (visited[a1][t2][t3] == 0) {
				visited[a1][t2][t3] = 1;
				q.push(info(a1, t2, t3));
			}
		}
		else if (a2 + a3 <= C) {
			int t2 = 0;
			int t3 = a2 + a3;
			if (visited[a1][t2][t3] == 0) {
				visited[a1][t2][t3] = 1;
				q.push(info(a1, t2, t3));
			}
		}
		//b->a
		if (a2 + a1 > A) {
			int t2 = a2 + a1 - A;
			int t1 = A;
			if (visited[t1][t2][a3] == 0) {
				visited[t1][t2][a3] = 1;
				q.push(info(t1, t2, a3));
			}
		}
		else if (a2 + a1 <= A) {
			int t2 = 0;
			int t1 = a1 + a2;
			if (visited[t1][t2][a3] == 0) {
				visited[t1][t2][a3] = 1;
				q.push(info(t1, t2, a3));
			}
		}
		
		//c->a
		if (a3 + a1 > A) {
			int t3 = a3 + a1 - A;
			int t1 = A;
			if (visited[t1][a2][t3] == 0) {
				visited[t1][a2][t3] = 1;
				q.push(info(t1, a2, t3));
			}
		}
		else if (a3 + a1 <= A) {
			int t3 = 0;
			int t1 = a1 + a3;
			if (visited[t1][a2][t3] == 0) {
				visited[t1][a2][t3] = 1;
				q.push(info(t1, a2, t3));
			}
		}
		//c->b
		if (a3 + a2 > B) {
			int t3 = a3 + a2 - B;
			int t2 = B;
			if (visited[a1][t2][t3] == 0) {
				visited[a1][t2][t3] = 1;
				q.push(info(a1, t2, t3));
			}
		}
		else if (a3 + a2 <= B) {
			int t3 = 0;
			int t2 = a3 + a2;
			if (visited[a1][t2][t3] == 0) {
				visited[a1][t2][t3] = 1;
				q.push(info(a1, t2, t3));
			}
		}

	}

}

int main(void) {

	cin >> A >> B >> C;
	
	bfs();
	
	sort(rst.begin(), rst.end());
	for (int i = 0; i < rst.size(); i++) {
		cout << rst[i] << " ";
	}
	cout << '\n';

	return 0;
}
