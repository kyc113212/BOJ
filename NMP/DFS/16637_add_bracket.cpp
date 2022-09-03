
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>
#include <queue>

#define MAX_V 987654321
#define MOD_V 1000000007
#define T_MAX_V 1000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int N;
string s;
int maxV = -MAX_V;

int calc(int num, char op, int num2) {
	switch (op)
	{
	case '+':
		return num + num2;
	case '-':
		return num - num2;
	case '*':
		return num * num2;
	default:
		break;
	}
	return 0;
}

void dfs(int idx, int num) {
	if (idx == N - 1) {
		maxV = max(maxV, num);
		return;
	}
	char op = s[idx + 1];
	if (idx == N - 3) {
		// 무조건 계산
		dfs(idx + 2, calc(num, op, s[idx + 2] - '0'));
	}
	// 괄호 있이 계산
	if (idx + 4 < N) {
		// 괄호 계산
		int temp = calc(s[idx + 2] - '0', s[idx + 3], s[idx + 4] - '0');
		dfs(idx + 4, calc(num, op, temp));
	}
	// 괄호 없이 계산
	if (idx + 2 < N) {
		dfs(idx + 2, calc(num, op, s[idx + 2] - '0'));
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> s;
	dfs(0, s[0] - '0');

	cout << maxV << '\n';


	return 0;
}
