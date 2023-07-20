#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>
#include <queue>

#define MAX_V 987654321
#define MOD_V 1000000007
#define T_MAX_V 1000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int N;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
bool visited[101][101];
int arr[101][101];

bool bfs(int mx, int mi) {
	if (arr[0][0] > mx || arr[0][0] < mi)
		return false;
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		if (cy == N - 1 && cx == N - 1) {
			return true;
		}
		if (visited[cy][cx])
			continue;
		visited[cy][cx] = true;
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (visited[ny][nx])
				continue;
			if (arr[ny][nx] > mx || arr[ny][nx] < mi)
				continue;
			q.push(make_pair(ny, nx));
		}
	}

	return false;
}

bool check(int mid) {
	for (int i = 0; i + mid <= 200; i++) {
		if (bfs(i + mid, i)) {
			return true;
		}
	}
	return false;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int left = 0;
	int right = 200;
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			right = mid - 1;
			ans = mid;
		}
		else {
			left = mid + 1;
		}
	}

	cout << ans << '\n';
	return 0;
}
