#include <iostream>
#include <string>
#include <vector>

using namespace std;

int pi[1000001];
string T, P;

void make_fail_func(string pattern) {

	int j = 0;
	for (int i = 1; i < pattern.size(); i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			pi[i] = ++j;
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);

	getline(cin, T);
	getline(cin, P);

	make_fail_func(P);
	int j = 0;
	int cnt = 0;
	vector<int> v;

	for (int i = 0; i < T.size(); i++) {
		while (j > 0 && T[i] != P[j]) {
			j = pi[j - 1];
		}
		if (T[i] == P[j]) {
			if (j == P.size() - 1) {
				cnt++;
				v.push_back(i - P.size() + 2);
				j = pi[j];
			}
			else
				j++;
		}
	}
	
	cout << cnt << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;


	return 0;
}
