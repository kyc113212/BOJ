#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int arr[100001];

int main() {

	cin >> N;
	vector<int> rst;
	priority_queue<int, vector<int>, less<int>> maxheap;		//큰게 top
	priority_queue<int, vector<int>, greater<int>> minheap;		//작은게 top

	for (int i = 0; i < N; i++) {
		cin >> arr[i];

	}

	for (int i = 0; i < N; i++) {
		if (maxheap.size() == minheap.size()) {
			maxheap.push(arr[i]);
		}
		else
			minheap.push(arr[i]);

		if (maxheap.size() != 0 && minheap.size() != 0) {
			if (maxheap.top() > minheap.top()) {
				int maxheapV = maxheap.top();
				int minheapV = minheap.top();
				maxheap.pop();
				minheap.pop();
				if (minheapV < maxheapV) {
					maxheap.push(minheapV);
					minheap.push(maxheapV);
				}
			}			
		}
		rst.push_back(maxheap.top());
	}

	for (int i = 0; i < rst.size(); i++) {
		cout << rst[i] << ' ';
	}
	cout << '\n';



	return 0;
}
