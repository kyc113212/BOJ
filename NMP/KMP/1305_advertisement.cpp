#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string s;
int arr[1000001];

int main() {

	cin >> N;
	cin >> s;
	int ans_idx = 0;

	int j = 0;
	for (int i = 1; i < s.size(); i++) {
		while (j > 0 && s[i] != s[j]) {
			j = arr[j - 1];
		}
		if (s[i] == s[j]) {
			arr[i] = ++j;
			ans_idx = max(ans_idx, arr[i]);
		}
	}

	cout << N - arr[N-1] << '\n';
	


	return 0;
}
