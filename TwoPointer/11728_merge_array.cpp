#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int a[1000005], b[1000005];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> b[i];
	}

	sort(a, a + N);
	sort(b, b + M);

	int s1 = 0;
	int s2 = 0;
	while (1) {

		if (s1 == N && s2 == M)
			break;

		if (s1 < N && s2 < M) {
			if (a[s1] < b[s2]) {
				cout << a[s1++] << ' ';
			}
			else {
				cout << b[s2++] << ' ';
			}
		}
		else if (s1 == N && s2 < M) {
			cout << b[s2++] << " ";
		}
		else if (s1 < N && s2 == M) {

			cout << a[s1++] << " ";
		}		
	}
	cout << '\n';

	return 0;
}
