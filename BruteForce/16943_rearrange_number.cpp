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
string a, b;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	sort(a.begin(), a.end());
	bool flag = false;
	sort(a.begin(), a.end(), greater<>());
	do {
		if (a[0] == '0') {
			continue;
		}
		if (stoi(a) < stoi(b)) {			
			cout << a << '\n';
			flag = true;
			break;
		}
	} while (prev_permutation(a.begin(), a.end()));
	if (!flag)
		cout << -1 << '\n';


	return 0;
}
