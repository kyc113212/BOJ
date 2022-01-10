#include <iostream>
#include <algorithm>

using namespace std;

#define INF 987654321

int DP[10005];
int arr[] = { 300,60,10 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int a = 0;
	int b = 0;
	int c = 0;
	for (int i = 0; i < 3; i++) {
		while (N - arr[i] >= 0) {
			if (i == 0)
				a++;
			if (i == 1)
				b++;
			if (i == 2)
				c++;
			N -= arr[i];
		}
	}

	if (N == 0)
		cout << a << " " << b << " " << c << '\n';
	else
		cout << -1 << '\n';
	return 0;
}
