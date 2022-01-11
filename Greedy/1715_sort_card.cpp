#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[100005];
int ans = 0;

struct cmp {
	bool operator()(int &a, int &b) {
		return a > b;
	}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	priority_queue<int, vector<int>, cmp> pq;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}

	int ans = 0;

	while (pq.size() > 1) {
		int n1 = pq.top();
		pq.pop();
		int n2 = pq.top();
		pq.pop();
		ans += (n1 + n2);
		pq.push(n1 + n2);
	}

	cout << ans << '\n';

	return 0;
}
