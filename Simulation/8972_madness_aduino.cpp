#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>

#define MAX_V 987654321

struct info {
	int y, x;
	bool alive;
	info(int y, int x, bool a) : y(y), x(x), alive(a) {}
};

using namespace std;
typedef long long ll;
int R, C;
int map[101][101];
int cnt_map[101][101];
int dy[] = { 0,1,1,1,0,0,0,-1,-1,-1 };
int dx[] = { 0,-1,0,1,-1,0,1,-1,0,1 };
vector<info> jong, aduino;

int solve() {


	string t;
	cin >> t;
	vector<int> a_dir;
	for (int i = 0; i < t.size(); i++) {
		a_dir.push_back(t[i] - '0');
	}


	for (int i = 0; i < a_dir.size(); i++) {
		memset(cnt_map, 0, sizeof(cnt_map));
		int njy = jong[0].y + dy[a_dir[i]];
		int njx = jong[0].x + dx[a_dir[i]];
		cnt_map[njy][njx] = MAX_V;
		map[jong[0].y][jong[0].x] = 0;
		map[njy][njx] = 1;
		jong[0].y = njy;
		jong[0].x = njx;
		//종수가 간곳이 아두이노가 있는 경우 return ans;
		for (int j = 0; j < aduino.size(); j++) {
			if (aduino[j].alive == true) {
				// 현재 종수가 아두이노와 겹쳤는지 확인
				if (aduino[j].y == njy && aduino[j].x == njx) {
					return i + 1;
				}
				// 아니면 아두이노를 종수와 제일 방향을 찾음
				int min_d = MAX_V;
				int min_i = -1;
				int cay = aduino[j].y;
				int cax = aduino[j].x;

				for (int k = 1; k <= 9; k++) {
					int nay = cay + dy[k];
					int nax = cax + dx[k];
					if (nay < 0 || nax < 0 || nay >= R || nax >= C)
						continue;
					int dist = abs(njy - nay) + abs(njx - nax);
					if (min_d > dist) {
						min_i = k;
						min_d = dist;
					}
				}
				if (cay + dy[min_i] == njy && cax + dx[min_i] == njx) {
					return i + 1;
				}
				//아두이노 이동
				int nay = cay + dy[min_i];
				int nax = cax + dx[min_i];
				cnt_map[nay][nax]++;
				map[cay][cax] = 0;
				map[nay][nax] = 2;
				aduino[j].y = nay;
				aduino[j].x = nax;
			}
			
		}
		//cnt map에서 2이상인 값을 찾고, 해당 좌표를 가진 아두이노를 모두 없앰 alive false상태로 변경
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				if (cnt_map[j][k] > 1 && cnt_map[j][k] != MAX_V) {
					for (int m = 0; m < aduino.size(); m++) {
						if (aduino[m].alive) {
							if (j == aduino[m].y && k == aduino[m].x) {
								aduino[m].alive = false;
							}
						}
					}
					cnt_map[j][k] = 0;
					map[j][k] = 0;
				}
			}
		}

		int uu = 0;

		//아두이노 이동시 종수와 접촉하는 경우 게임 끝
		//아두이노끼리 부디치면 alive false로 함
 	}

	return -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			if (s[j] == 'I') {
				map[i][j] = 1;
				jong.push_back(info(i, j, true));
			}
			else if (s[j] == 'R') {
				map[i][j] = 2;
				aduino.push_back(info(i, j, true));
			}
		}
	}
	int ans = solve();
	if (ans == -1) {
		//맵 출력
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (cnt_map[i][j] == 1) {
					cout << 'R';
				}
				else if (cnt_map[i][j] == MAX_V) {
					cout << 'I';
				}
				else {
					cout << '.';
				}
			}
			cout << '\n';
		}
	}
	else {
		cout << "kraj " << ans << '\n';
	}

	return 0;
}
