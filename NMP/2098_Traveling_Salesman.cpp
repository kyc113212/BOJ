#include <iostream>
#include <algorithm>

using namespace std;

#define INF 987654321
int N;
int map[16][16];
int DP[16][1 << 16];

int TSP(int cur, int visit) {

	int rst = DP[cur][visit];
	if (rst != 0)
		return rst;

	if (visit == ((1<<N) - 1)) {
		if (map[cur][0] != 0)
			return map[cur][0];
		else
			return INF;
	}

	rst = INF;

	for (int i = 0; i < N; i++) {
		if (map[cur][i] == 0 || (visit & (1 << i)))
			continue;
		rst = min(rst, TSP(i, visit | (1 << i)) + map[cur][i]);
	}

	DP[cur][visit] = rst;
	return rst;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	cout << TSP(0, 1) << '\n';
	
	return 0;
}
