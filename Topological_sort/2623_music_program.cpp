#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[1001];
int visited[1001];
int N, K;
vector<int> graph[1001];

int main() {

	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		int a;
		cin >> a;
		vector<int> temp;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			temp.push_back(b);			
		}
		for (int j = 0; j < temp.size() - 1; j++) {
			graph[temp[j]].push_back(temp[j + 1]);
			arr[temp[j + 1]]++;
		}
	}

	queue<int> now;
	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) {
			now.push(i);
		}
	}

	//불가능한경우 0으로 표시
	vector<int> rst;

	while (!now.empty()) {
		int cur = now.front();
		now.pop();
		if (arr[cur] == 0 && visited[cur] == 0) {
			rst.push_back(cur);
			visited[cur] = 1;
		}
		for (int i = 0; i < graph[cur].size(); i++) {
			if (--arr[graph[cur][i]] == 0) {
				now.push(graph[cur][i]);
			}
		}
	}
	
	bool flag = false;
	for (int i = 1; i <= N; i++) {
		if (arr[i] != 0) {
			cout << 0 << '\n';
			flag = true;
		}
	}
	if (flag == false) {
		for (int i = 0; i < rst.size(); i++) {
			cout << rst[i] << '\n';
		}
	}


	return 0;
}
