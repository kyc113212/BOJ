#include <iostream>
#include <vector>

using namespace std;

int L, P, V;
vector<int> v;

int main() {
	while (1) {
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)
			break;

		int div = V / P;
		int mod = 0;
		if (V%P > L) {
			mod = L;
		}
		else {
			mod = V % P;
		}
		v.push_back(div * L + mod);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << "Case " << i+1 << ": " << v[i] << '\n';
	}



	return 0;
}
