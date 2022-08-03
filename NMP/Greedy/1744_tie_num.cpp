#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> m, z, o1, o2;

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a < 0)
			m.push_back(a);
		if (a == 0)
			z.push_back(a);
		if (a > 1)
			o1.push_back(a);
		if (a == 1)
			o2.push_back(a);

	}

	sort(m.begin(), m.end());
	sort(o1.begin(), o1.end());

	int ans = 0;

	if (m.size() % 2 == 1) {
		for (int i = 1; i < m.size(); i+=2) {
			ans += (m[i] * m[i - 1]);
		}
		if (z.size() == 0) {
			ans += m[m.size() - 1];
		}
	}
	else {
		for (int i = 1; i < m.size(); i += 2) {
			ans += (m[i] * m[i - 1]);
		}
	}

	if (o1.size() % 2 == 1) {
		for (int i = o1.size() - 1; i >=1; i-=2) {
			ans += (o1[i] * o1[i - 1]);
		}
		ans += o1[0];
	}
	else {
		for (int i = o1.size() - 1; i >= 1; i -= 2) {
			ans += (o1[i] * o1[i - 1]);
		}
	}

	ans += (o2.size());
	cout << ans << '\n';
	

	return 0;
}
