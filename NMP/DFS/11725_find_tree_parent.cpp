#include <iostream>
#include <vector>

using namespace std;

int N;
int visited[100005];
vector<int> graph[100005];
vector<int> rst;

void find_parent(int v) {
	visited[v] = true;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		if (!visited[next]) {
			rst[next] = v;
			find_parent(next);
		}
	}
}

int main() {

	cin >> N;
	rst.resize(N + 1);

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	find_parent(1);

	for (int i = 2; i <= N; i++) {
		cout << rst[i] << " ";
	}
	cout << '\n';
	


	return 0;
}
