#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>
#include <queue>

#define MAX_V 987654321
#define MOD 100000009
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

char graph[51][51];
int visited[51][51];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int N, M;
int sy, sx;

bool dfs(int y, int x, int cnt) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny == sy && nx == sx && visited[ny][nx]) {
            if (cnt >= 4) {
                return true;
            }
        }

        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;

        if (graph[ny][nx] != graph[y][x])
            continue;

        if (visited[ny][nx])
            continue;

        visited[ny][nx] = 1;

        if (dfs(ny, nx, cnt + 1)) {
            return true;
        }
        visited[ny][nx] = 0;
    }
    return false;
}

int main() {

	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            graph[i][j] = s[j];
        }
    }

    bool check = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!check) {
                sy = i;
                sx = j;
                visited[i][j] = 1;

                if (dfs(i, j, 1)) {
                    check = true;
                }
                visited[i][j] = 0;
            }
        }
    }

    if (check) {
        cout << "Yes" << '\n';
    }
    else
        cout << "No" << '\n';

	return 0;
}
