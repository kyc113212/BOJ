#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>

#define endl "\n"

using namespace std;

int N, M;
int arr[100010];
vector<int> graph[100010];

int main() {

	cin >> N >> M;

	deque<pair<int, int>> dq;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[b]++;
		graph[a].push_back(b);
	}

	deque<int> now;

	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) {
			now.push_back(i);
		}
	}

	while(!now.empty()) {
		int i = now.front();
		now.pop_front();
		cout << i << " ";
		for (int j = 0; j < graph[i].size(); j++) {
			if (--arr[graph[i][j]] == 0) {
				now.push_back(graph[i][j]);
			}
		}
	}
	
	

	return 0;
}
