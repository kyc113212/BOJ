#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <cstring>
#include <queue>

#define MAX_V 987654321
#define MOD 100000007
#define T_MAX_V 1000000000
#define TREE_HEIGHT 20
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	vector<int> num;
	vector<char> op;
	int i = 0;
	while (i < s.size()) {
		if (s[i] >= '0' && s[i] <= '9') {
			string temp = "";
			for (int m = i; m < s.size(); m++) {
				if (s[m] >= '0' && s[m] <= '9') {
					temp += s[m];
				}
				else {
					num.push_back(stoi(temp));
					i = m - 1;
					break;
				}				
				if(m == s.size()-1) {
					num.push_back(stoi(temp));
					i = m;
				}
			}
		}
		else {
			op.push_back(s[i]);
		}
		i++;
	}

	int ans = num[0];
	i = 0;
	while (i < op.size()) {
		if (op[i] == '+') {
			ans += num[i + 1];
		}
		else {
			int temp_num = num[i + 1];
			int j = i + 1;
			if (j == op.size()) {
				ans -= temp_num;
			}
			else {
				for (; j < op.size(); j++) {
					if (j == op.size() - 1 || op[j] == '+') {
						temp_num += num[j + 1];
						i = j;
					}
					else {
						i = j - 1;
						break;
					}
				}
				ans -= temp_num;
			}
		}
		i++;
	}

	cout << ans << '\n';

	return 0;
}
