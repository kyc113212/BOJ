#include <iostream>
#include <vector>

using namespace std;
int N;
vector<int> v;
int arr[4000001];

int main() {	
	cin >> N;
	arr[0] = true;
	arr[1] = true;
	v.push_back(0);

	for (int i = 2; i*i < 4000001; i++) {
		for (int j = i * i; j < 4000001; j += i) {
			arr[j] = 1;
		}
	}

	int sum = 0;
	for (int i = 2; i <= 4000000; i++) {
		if (arr[i] == 0) {
			sum += i;
			v.push_back(sum);
		}
	}

	int left = 0;
	int right = 0;
	int ans = 0;
	while (left <= right && right <v.size()) {
		if (v[right] - v[left] > N) {
			left++;
		}
		else if (v[right] - v[left] < N) {
			right++;
		}
		else {
			right++;
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}
