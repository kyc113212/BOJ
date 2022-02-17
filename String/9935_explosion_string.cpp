#include <iostream>
#include <string>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	cin >> a >> b;
	string ans = "";

	for (int i = 0; i < a.size(); i++) {
		ans += a[i];
		if (ans[ans.size()-1] == b[b.size() - 1]) {
			bool flag = false;
			int temp_idx = ans.size() - 1;
			for (int j = b.size() - 1; j >= 0; j--) {
				if (b[j] != ans[temp_idx]) {
					flag = true;
					break;
				}
				temp_idx--;
			}
			if (flag == false) {
				//string을 pop한다.
				for (int j = 0; j < b.size(); j++) {
					ans.pop_back();
				}
			}
		}
	}

	if (ans.size() > 0)
		cout << ans << '\n';
	else
		cout << "FRULA" << '\n';
	return 0;
}
