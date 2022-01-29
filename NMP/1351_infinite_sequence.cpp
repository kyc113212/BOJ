#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

ll N, P, Q;
map<ll, ll> m;

ll DFS(ll n) {
	if (m.count(n))
		return m[n];
	else
		return m[n] = DFS(n / P) + DFS(n / Q);
}

int main() {

	ios_base::sync_with_stdio(false);

	cin >> N >> P >> Q;

	m[0] = 1;
	cout << DFS(N) << '\n';

	return 0;
}
