#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int arr[32001];
int visited[32001];
vector<int> graph[32001];

struct cmp {
	bool operator() (int &a, int &b) {
		return a > b;
	}
};

int main() {

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[b]++;
		graph[a].push_back(b);
	}

	priority_queue<int, vector<int>, cmp> pq;

	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) {
			pq.push(i);
		}
	}
	

	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();
		if (arr[now] == 0 && visited[now] == 0) {
			visited[now] = 1;
			cout << now << " ";
		}
		for (int i = 0; i < graph[now].size(); i++) {
			if (--arr[graph[now][i]] == 0) {
				pq.push(graph[now][i]);
			}
		}
	}
	cout << '\n';

	
	return 0;
}
