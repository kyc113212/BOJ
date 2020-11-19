#include <iostream>
#include <queue>
#include <vector>
#define MAX 20001
#define INF 987654321

using namespace std;

int V, E, startN;
struct value {
	int to, weight;
	value(int a, int b) : to(a), weight(b) {}
};

struct cmp {
	bool operator() (value a, value b) {
		return a.weight > b.weight;
	}
};
//오름차순 사용

/******
pq.push({ -cost, vtx } ); 로 푸쉬하고, top()으로 받아올 때 다시 -를 붙여 +로 바꾸어 준다.
이런 식이 아닌, 우선순위 큐를 선언할 때 priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > pq;
로 선언해주어 오름차순으로 정렬되도록 해도 된다.
********/

vector<value> graph[MAX];
int dist[MAX];
//int visited[MAX]; ---

void dijkstra(int x) {
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}
	dist[startN] = 0;

	priority_queue<value, vector<value>, cmp> pq;
	pq.push(value(startN, 0));

	while (!pq.empty()) {
		int c_cost = pq.top().weight;
		int c_node = pq.top().to;
		pq.pop();
		if (dist[c_node] < c_cost)
			continue;

		for (int i = 0; i < graph[c_node].size(); i++) {
			int n_node = graph[c_node][i].to;
			int n_cost = c_cost + graph[c_node][i].weight;
			if (dist[n_node] > n_cost) {
				dist[n_node] = n_cost;
				pq.push(value(n_node, n_cost));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (startN == i)
			cout << 0 << endl;
		else if (dist[i] == INF)
			cout << "INF" << endl;
		else
			cout << dist[i] << endl;
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> startN;
	for (int i = 0; i < E; i++) {
		int f, t, w;
		cin >> f >> t >> w;
		graph[f].push_back(value(t,w));
	}
	
	dijkstra(startN);

	return 0;
}
