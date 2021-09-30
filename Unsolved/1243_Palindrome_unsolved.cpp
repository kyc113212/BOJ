#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct s_info {
	string s;
	int size;
	s_info(string a, int b) : s(a), size(b) {}
};

int N;
int L;
vector<s_info> v;
int ans = 0;

void dfs(vector<s_info> tv, int idx, int size) {
	if (size > L)
		return;
	if (size == L) {
		//펠린드롬 구분
		string ts;
		for (int i = 0; i < tv.size(); i++) {
			ts += tv[i].s;
		}
		int cnt_l = 0;
		int cnt_r = L-1;
		int cnt = 0;
		bool flag = false;
		while (cnt < size/2) {
			if (ts[cnt_l] != ts[cnt_r]) {
				flag = false;
				return;
			}
			cnt_l++;
			cnt_r--;
			cnt++;
		}
		ans++;

		return;
	}
	for (int i = 0; i < N; i++) {
		tv.push_back(s_info(v[i].s, v[i].size));
		dfs(tv, i, size + v[i].size);
		tv.pop_back();
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		string t_s;
		cin >> t_s;
		v.push_back(s_info(t_s,t_s.size()));
	}

	vector<s_info> tv;
	for (int i = 0; i < N; i++) {
		tv.push_back(s_info(v[i].s, v[i].size));
		dfs(tv, i, v[i].size);
		tv.pop_back();
	}

	cout << ans << endl;


	return 0;
}
