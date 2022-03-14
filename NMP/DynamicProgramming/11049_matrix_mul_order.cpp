// 처음부터 다시 고민해야하는 문제
// 다시 고민해봐도 아이디어가 잘 들어오지 않는다.

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define INF 1000000000

int N;
int matrix[502][2];
long long DP[502][502];

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> matrix[i][0];
		cin >> matrix[i][1];
	}

	fill(&DP[0][0], &DP[501][502], INF);
	for (int i = 1; i < N; i++) {
		DP[i][i + 1] = matrix[i][0] * matrix[i][1] * matrix[i + 1][1];
	}
	for (int i = 1; i <= N; i++) {
		DP[i][i] = 0;
	}
	
	for (int i = 1; i < N; i++) {
		for (int j = 1; i + j <= N; j++) {
			for (int k = j; k <= i + j; k++) {
				DP[j][i + j] = min(DP[j][i + j], DP[j][k] + DP[k+1][i+j] + matrix[j][0] * matrix[k][1] * matrix[i+j][1]);
			}
		}
	}

	cout << DP[1][N] << '\n';

	return 0;
}
