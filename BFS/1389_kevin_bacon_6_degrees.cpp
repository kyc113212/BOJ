#include <iostream>
#include <queue>

using namespace std;

int user, relation;
int map[101][101];
int visited[101];
int dist[101];
int total_dist;
int min_index = 0;
int value;
int res = 99999;

void init(int arr[]) {
	for (int i = 0; i <= 101; i++) {
		arr[i] = 0;
	}
}

int main() {

	cin >> user >> relation;
	queue<int> q;

	for (int i = 0; i < relation; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	for (int i = 1; i <= user; i++) {
		q.push(i);
		visited[i] = true;
		while (!q.empty()) {
			int temp = q.front();
			q.pop();
			for (int j = 1; j <= user; j++) {
				if (visited[j] == false && map[temp][j] == 1) {
					visited[j] = true;
					dist[j] = dist[temp] + 1;
					q.push(j);
				}
			}			
		}
		for (int k = 1; k <= user; k++) {
			total_dist += dist[k];
		}

		if (res > total_dist) {
			res = total_dist;
			min_index = i;
		}

		init(dist);
		init(visited);
		total_dist = 0;
	}

	/*for (int k = 1; k <= user; k++) {
		for (int w = 1; w <= user; w++) {
			if(total_dist[k] < )
		}
	}*/

	cout << min_index << endl;

	return 0;
}
