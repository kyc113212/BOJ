#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define ld long double

struct pos {
	ld y, x;
	pos(ld y, ld x) : y(y), x(x) {}
};

ld calc_area(ld x1, ld y1, ld x2, ld y2) {
	return x1*y2 - y1 * x2;
}

int main() {

	ld N;
	cin >> N;
	vector<pos> v;
	for (ld i = 0; i < N; i++) {
		ld a, b;
		cin >> a >> b;
		v.push_back(pos(a, b));
	}

	ld rst = 0;
	for (ld i = 1; i < N - 1; i++) {
		rst += calc_area(v[i].x - v[0].x, v[i].y - v[0].y, v[i + 1].x - v[0].x, v[i + 1].y - v[0].y) / 2.0;
	}

	printf("%.1Lf\n", abs(rst));

	return 0;
}
