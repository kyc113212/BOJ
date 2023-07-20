#include <iostream>

using namespace std;

long long N;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int arr[10001] = { 0, };

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr[a] += 1;
	}

	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i << '\n';
		}
	}


	return 0;
}
