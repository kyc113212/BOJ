#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>

#define MAX_V 987654321
#define MOD 100000009
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string add_s(string s1, string s2) {
	string ans;
	vector<char> sc1, sc2;
	int s_size = 0;
	if (s1.size() > s2.size()) {
		sc1.resize(s1.size() + 1, '0');
		sc2.resize(s1.size() + 1, '0');
		s_size = s1.size() + 1;
	}
	else {
		sc1.resize(s2.size() + 1, '0');
		sc2.resize(s2.size() + 1, '0');
		s_size = s2.size() + 1;
	}


	for (int i = s1.size() - 1, j = 0; i >= 0; i--, j++) {
		sc1[j] = s1[i];
	}
	for (int i = s2.size() - 1, j = 0; i >= 0; i--, j++) {
		sc2[j] = s2[i];
	}

	vector<char> t_ans;
	t_ans.resize(s_size);
	for (int i = 0; i < s_size; i++) {
		int t_v = (sc1[i] - '0') + (sc2[i] - '0');
		if (t_v / 10 >= 1) {
			t_ans[i + 1] = '1';
		}
		if (t_ans[i] == '1') {
			int tt_v = t_v + 1;
			if (tt_v / 10 >= 1) {
				t_ans[i + 1] = '1';
			}
			t_ans[i] = (tt_v % 10) + '0';
		}
		else {
			t_ans[i] = (t_v % 10) + '0';
		}
	}

	for (int i = t_ans.size() - 1; i >= 0; i--) {
		if (i == t_ans.size() - 1) {
			if (t_ans[i] == '0')
				continue;
		}
		ans += t_ans[i];
	}

	// 앞자리가 0이면 pass, 아니면 ans에다가 넣는 걸로

	int tad = 0;
	return ans;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;
	
	cout << add_s(s1,s2) << '\n';

	return 0;
}
