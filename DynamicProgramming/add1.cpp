#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[1000001];

int main() {

	int N;
	cin >> N;
	for (int i = 0; i <= N; i++)
		arr[i] = 987654321;

	arr[1] = 0;

	for (int i = 1; i <= N; i++) {
		if(i+1 <= N)
			arr[i + 1] = min(arr[i + 1], arr[i] + 1);
		if (i * 2 <= N)
			arr[i * 2] = min(arr[i * 2], arr[i] + 1);
		if (i * 3 <= N)
			arr[i * 3] = min(arr[i * 3], arr[i] + 1);
	}

	cout << arr[N] << endl;

	return 0;
}
