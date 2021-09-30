#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int map[51][51];

int WB(int y, int x) {

	int cnt = 0;

	//W부터 시작할때
	for (int i = y; i < y+8; i++) {
		for (int j = x; j < x+8; j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				if (map[i][j] != 'W')
					cnt++;
			}
			else if (i % 2 == 1 && j % 2 == 0) {
				if (map[i][j] != 'B')
					cnt++;
			}
			else if (i % 2 == 0 && j % 2 == 1) {
				if (map[i][j] != 'B')
					cnt++;
			}
			else if (i % 2 == 1 && j % 2 == 1) {
				if (map[i][j] != 'W')
					cnt++;
			}
		}
	}

	return cnt;

}

int BW(int y, int x) {

	int cnt = 0;

	//W부터 시작할때
	for (int i = y; i < y+8; i++) {
		for (int j = x; j < x+8; j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				if (map[i][j] != 'B')
					cnt++;
			}
			else if (i % 2 == 1 && j % 2 == 0) {
				if (map[i][j] != 'W')
					cnt++;
			}
			else if (i % 2 == 0 && j % 2 == 1) {
				if (map[i][j] != 'W')
					cnt++;
			}
			else if (i % 2 == 1 && j % 2 == 1) {
				if (map[i][j] != 'B')
					cnt++;
			}
		}
	}

	return cnt;

}

int main() {

	int N, M;
	cin >> N >> M;
	int rst = 987654321;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j];
		}
	}
	
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int rst1 = WB(i, j);
			int rst2 = BW(i, j);
			rst = min(rst, min(rst1, rst2));
		}
	}

	//B부터 시작할때
	

	cout << rst << endl;



	return 0;
}
