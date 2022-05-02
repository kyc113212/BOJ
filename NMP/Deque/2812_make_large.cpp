#include <iostream>
#include <string>
#include <deque>

using namespace std;

int N, K;
string s;

int main() {

	cin >> N >> K;
	cin >> s;
	deque<char> dq;

	for (int i = 0; i < s.size(); i++) {

		while (K && !dq.empty() && s[i] > dq.back() ) {
			dq.pop_back();
			K--;
		}
		dq.push_back(s[i]);
	}

	for (int i = 0; i < dq.size() - K; i++) {
		cout << dq[i];
	}
	cout << '\n';



	return 0;
}
