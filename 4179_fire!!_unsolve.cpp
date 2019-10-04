#include <iostream>
#include <string>
#include <queue>

using namespace std;

char map[1001][1001];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct pos {
	int y, x;
	pos(int a, int b) : y(a), x(b) {}
};

int main() {

	
	int R, C;
	cin >> R >> C;
	queue<pos> fire;
	queue<pos> jihoon;

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'J')
				jihoon.push(pos(i, j));
			else if (map[i][j] == 'F')
				fire.push(pos(i, j));
		}
	}


	return 0;
}
