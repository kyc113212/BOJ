#include <iostream>
#include <algorithm>

using namespace std;

int arr[100005];
int N;
int X;

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> X;
	sort(arr, arr + N);

	int st = 0;
	int ed = N-1;
	int sum = arr[st] + arr[ed];

	int ans = 0;

	while (st < ed ) {

		sum = arr[st] + arr[ed];

		if (sum == X) {
			ans++;
			st++;
			ed--;
		}
		else if (sum < X) {
			st++;
		}
		else {
			ed--;
		}
	}

	cout << ans << '\n';

	return 0;
}
