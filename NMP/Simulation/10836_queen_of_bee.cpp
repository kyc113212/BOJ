#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>

#define MAX_V 1000000001

using namespace std;
typedef long long ll;

int N, M;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	vector<int> map;
	map.resize(2 * N - 1, 1);

	for (int i = 0; i < M; i++) {
		
		int zero, one, two;
		cin >> zero >> one >> two;
		for (int j = zero; j < zero + one; j++) {
			map[j] += 1;
		}
		for (int j = zero + one; j < map.size(); j++) {
			map[j] += 2;
		}
		// 현재 7바퀴 돌면 다음 5바퀴 다음 3바퀴
		/*int cnt = 1;

		for (int j = 0; j < N - 1; j++) {
			//나머지칸 최대값을 찾자
			//가운데 값의 최대값을 확인한 후에 그 오른쪽, 아래쪽의 최대값을 찾자
			int tmaxV = max(growth[cnt - 1][cnt], max(growth[cnt][cnt - 1], growth[cnt - 1][cnt - 1]));
			map[cnt][cnt] += tmaxV;
			growth[cnt][cnt] = tmaxV;
			//아래쪽 이동
			int cy = cnt + 1;
			while (cy < N) {
				int maxV = max(growth[cy - 1][cnt], max(growth[cy][cnt - 1], growth[cy - 1][cnt - 1]));
				map[cy][cnt] += maxV;
				growth[cy][cnt] = maxV;
				cy++;
			}
			int cx = cnt + 1;
			while (cx < N) {
				int maxV = max(growth[cnt - 1][cx], max(growth[cnt][cx - 1], growth[cnt - 1][cx - 1]));
				map[cnt][cx] += maxV;
				growth[cnt][cx] = maxV;
				cx++;
			}
			cnt++;
		}*/
	}

	for (int i = 0; i < N; i++) {
		cout << map[N - 1 + i] << ' ';
	}
	cout << '\n';
	int cnt = N - 2;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j == 0) {
				cout << map[cnt--] << ' ';
			}
			else {
				cout << map[N - 1 + j] << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
