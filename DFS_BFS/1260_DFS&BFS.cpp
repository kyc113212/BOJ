#include <iostream>
#include <queue>

using namespace std;
int map[1001][1001];
bool visited[1001];
int vertex1, vertex2, vertexT;
int line;
int startV;
void dfs(int v);

int main(){
	queue<int> q;

	cin >> vertexT >> line >> startV;
	for (int i = 0; i < line; i++){
		cin >> vertex1 >> vertex2;
		map[vertex1][vertex2] = 1;
		map[vertex2][vertex1] = 1;
	}

	dfs(startV);
	cout << endl;
	for (int i = 1; i <= vertexT; i++)
		visited[i] = false;

	q.push(startV);
	visited[startV] = true;
	while(!q.empty()){
		int num = q.front();
		q.pop();
		cout << num << " ";
		for (int i = 1; i <= vertexT; i++){
			if (visited[i] == false && map[num][i] == 1){
				visited[i] = true;
				q.push(i);
			}
		}
	}
	cout << endl;

	return 0;
}

void dfs(int v){
	visited[v] = true;
	cout << v << " ";
	for (int i = 1; i <= vertexT; i++){
		if (map[v][i] == 1 && visited[i] == false){
			dfs(i);
		}
	}
}
