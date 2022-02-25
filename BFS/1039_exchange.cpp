#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

struct info {
	string num;
	int cnt;
	info(string a, int b) : num(a), cnt(b) {}
};

string s;
int K;
int maxV = 0;

int bfs() {

	///////////////////// 예외처리
	/*bool flag = false;
	char c = s[0];
	for (int i = 0; i < s.size(); i++) {
		//모두 같은 숫자인 경우
		if (c != s[i])
			flag = true;
	}
	if (!flag)
		return -1;
	//숫자 하나 뺴고 모두 0인경우
	int zero_cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')
			zero_cnt++;
	}
	if (s.size() == 2 && zero_cnt > 0)
		return -1;*/

	////////////////////////////////////////////////// 정상적인 문제풀이
	queue<info> q;
	q.push(info(s, K));
	bool flag = false;

	for (int i = 0; i < K; i++) {	//변경하는 횟수
		int q_size = q.size();
		map<string, bool> m;

		for (int j = 0; j < q_size; j++) {
			string c_num = q.front().num;
			int c_cnt = q.front().cnt;
			q.pop();

			for (int i = 0; i < s.size(); i++) {
				for (int j = i + 1; j < s.size(); j++) {
					string temp_num = c_num;
					swap(temp_num[i], temp_num[j]);
					if (temp_num[0] == '0')
						continue;
					if (m.count(temp_num))
						continue;
					m.insert(make_pair(temp_num, true));
					q.push(info(temp_num, c_cnt - 1));
				}
			}
		}

	}
	if (q.size() > 0) {
		while (!q.empty()) {
			maxV = max(maxV, stoi(q.front().num));
			q.pop();
		}
		//마지막에 size 비교 -> 숫자 하나 있으면 변경 불가
		return maxV;
	}
	else
		return -1;
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> K;
	
	cout << bfs() << '\n';

	return 0;
}
