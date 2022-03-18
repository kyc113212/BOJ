#include <iostream>
#include <queue>

using namespace std;

struct info {
	int time, clip_cnt, line_cnt;
	info(int a, int b, int c) : time(a), clip_cnt(b), line_cnt(c) {}
};

int N;
bool visited[1005][1005]; //현재상황에서 화면 이모티콘 갯수, 클립보드의 이모티콘 갯수 check

int bfs() {

	visited[1][0] = true;
	queue<info> q;
	q.push(info(0, 0, 1));

	while (!q.empty()) {
		int c_time = q.front().time;
		int c_clip_cnt = q.front().clip_cnt;
		int c_line_cnt = q.front().line_cnt;
		q.pop();

		if (c_line_cnt == N) {
			return c_time;
		}

		//3가지 방법으로 가공
		//1. 현재 값을 클립보드에 복사(클립보드 값 복사됨)
		//2. 현재 클립보드 값을 현재 화면에 붙여넣기
		//3. 현재 화면에서 이모티콘 하나 삭제

		//1번 방법
		if (c_line_cnt + c_line_cnt <= 1000) {
			if (!visited[c_line_cnt][c_line_cnt]) {
				visited[c_line_cnt][c_line_cnt] = 1;
				q.push(info(c_time + 1, c_line_cnt, c_line_cnt));
			}			
		}

		if (c_clip_cnt + c_line_cnt <= 1001) {
			if (!visited[c_clip_cnt + c_line_cnt][c_clip_cnt]) {
				visited[c_clip_cnt + c_line_cnt][c_clip_cnt] = 1;
				q.push(info(c_time + 1, c_clip_cnt, c_line_cnt + c_clip_cnt));
			}
		}

		if (c_line_cnt - 1 > 0) {
			if (!visited[c_line_cnt - 1][c_clip_cnt]) {
				visited[c_line_cnt - 1][c_clip_cnt] = 1;
				q.push(info(c_time + 1, c_clip_cnt, c_line_cnt - 1));
			}
		}
	}

	return -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	cout << bfs() << '\n';

	return 0;
}
