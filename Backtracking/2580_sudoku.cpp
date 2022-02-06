#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct pos {
	int y, x;
	pos(int a, int b) : y(a), x(b) {}
};

int map[9][9];
bool visited[10];
vector<pos> v;
int ans = 0;

vector<int> check_input(int y, int x) {
	
	memset(visited, false, sizeof(visited));
	for (int i = y+1; i < 9; i++) {
		if(map[i][x] != 0)
			visited[map[i][x]] = true;
	}
	for (int i = 0; i < y; i++) {
		if (map[i][x] != 0)
			visited[map[i][x]] = true;
	}
	for (int i = x + 1; i < 9; i++) {
		if (map[y][i] != 0)
			visited[map[y][i]] = true;
	}
	for (int i = 0; i < x; i++) {
		if (map[y][i] != 0)
			visited[map[y][i]] = true;
	}
	
	int s_y = (y / 3)*3;
	int s_x = (x / 3)*3;

	for (int i = s_y; i < s_y + 3; i++) {
		for (int j = s_x; j < s_x + 3; j++) {
			//한칸, 세로줄 가로줄
			if (map[i][j] != 0)
				visited[map[i][j]] = true;
		}
	}

	vector<int> v;
	for (int i = 1; i <= 9; i++) {
		if (visited[i] == false)
			v.push_back(i);
	}

	return v;
}

bool dfs(int idx) {
	//다음번쨰 idx 확인
	if (idx == v.size()) {
		//끝까지 찾았으므로 map 출력
		return true;
	}

	vector<int> tv = check_input(v[idx].y, v[idx].x);
	if (tv.size() == 0)
		return false;
	for (int i = 0; i < tv.size(); i++) {
		map[v[idx].y][v[idx].x] = tv[i];
		if (dfs(idx + 1)) {
			return true;
		}
		map[v[idx].y][v[idx].x] = 0;
	}

	return false;
}

int main() {

	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				v.push_back(pos(i, j));
		}
	}

	memset(visited, false, sizeof(visited));
	vector<int> tv = check_input(v[0].y, v[0].x);

	for (int i = 0; i < tv.size(); i++) {
		map[v[0].y][v[0].x] = tv[i];
		ans++;
		if (dfs(1)) {
			//map 출력
			for (int j = 0; j < 9; j++) {
				for (int k = 0; k < 9; k++) {
					cout << map[j][k] << ' ';
				}
				cout << '\n';
			}
			break;
		}
		ans--;
	}	


	return 0;
}
