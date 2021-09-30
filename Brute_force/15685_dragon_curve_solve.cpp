#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int map[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

bool check_rectangle(int y, int x) {
	if (map[y][x] == 1 && map[y + 1][x] == 1 && map[y][x + 1] == 1 && map[y + 1][x + 1] == 1)
		return true;
	else
		return false;
}

void draw_map(int y, int x, int dir, int generation) {
	map[y][x] = 1;
	int sx = x;
	int sy = y;
	vector<int> v;
	v.push_back(dir);
	for (int i = 0; i < generation; i++) {
		int K = pow(2, generation);
		vector<int> reverse_dir;
		int k = 0;
		for (int j = v.size() -1 ; j >= 0; j--) {
			reverse_dir.push_back(v[j] + 1);
			if (reverse_dir[k] == 4) {
				reverse_dir[k] = 0;
			}
			k++;
		}
		for (int j = 0; j < reverse_dir.size(); j++) {
			v.push_back(reverse_dir[j]);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		sx += dx[v[i]];
		sy += dy[v[i]];
		map[sy][sx] = 1;
	}

	return;
}

int main() {

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		draw_map(y,x,d, g);
	}

	int cnt = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (check_rectangle(i, j) == true)
				cnt++;
		}
	}

	cout << cnt << endl;


	return 0;
}
