#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


struct item {
	int to, cost;
	item(int a, int b) : to(a), cost(b) {}
};

struct cmp {
	bool operator() (item &a, item &b) {
		return a.cost > b.cost;
	}
};

vector<item> graph[1001];
bool visited[1001];
int N, M;

int main() {

	cin >> N >> M;
	priority_queue<item, vector<item>, cmp> pq;
	int startV = 0;
	int toV = 0;
	int min_cost = 99999;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(item(b, c));
		graph[b].push_back(item(a, c));
		if (min_cost > c) {
			startV = a;
			toV = b;
			min_cost = c;
		}
	}

	int ans = 0;

	visited[startV] = true;
	for (int i = 0; i < graph[startV].size(); i++) {

		pq.push(item(graph[startV][i].to, graph[startV][i].cost));
	}

	while (!pq.empty()) {
		int c_vertex = pq.top().to;
		int c_cost = pq.top().cost;
		pq.pop();
		if (visited[c_vertex])
			continue;
		visited[c_vertex] = true;
		ans += c_cost;
		for (int i = 0; i < graph[c_vertex].size(); i++) {
			if (visited[graph[c_vertex][i].to] == true)
				continue;
			else {
				//int next_cost = c_cost + graph[c_vertex][i].cost;
				pq.push(item(graph[c_vertex][i].to, graph[c_vertex][i].cost));
			}
		}
	}

	cout << ans << '\n';



	return 0;
}
