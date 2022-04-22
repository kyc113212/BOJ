#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int NUM, N;
int prohibit_btn[10];
int minV = 0;
vector<int> v;

void set_num(int num, int cnt) {
	if (cnt == v.size()) {
		// 위아래 계산
		// 최적의 수를 찾음
		if (num > NUM) {
			minV = min(minV, num - NUM);
		}
		else {
			minV = min(minV, NUM - num);
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (prohibit_btn[i])
			continue;
		num *= 10;
		num += i;
		set_num(num, cnt + 1);
		num -= i;
		num /= 10;
	}
	return;
}

void set_num2(int num, int cnt) {
	if (cnt == v.size()+1) {
		//위아래 계산
		if (num > NUM) {
			minV = min(minV, num - NUM);
		}
		else {
			minV = min(minV, NUM - num);
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (prohibit_btn[i])
			continue;
		num *= 10;
		num += i;
		set_num2(num, cnt + 1);
		num -= i;
		num /= 10;
	}
	return;
}

void set_num3(int num, int cnt) {
	if (cnt == v.size() - 1) {
		//위아래 계산
		if (num > NUM) {
			minV = min(minV, num - NUM);
		}
		else {
			minV = min(minV, NUM - num);
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (prohibit_btn[i])
			continue;
		num *= 10;
		num += i;
		set_num3(num, cnt + 1);
		num -= i;
		num /= 10;
	}
	return;
}

int main() {

	cin >> NUM;
	int temp_v = NUM;
	if (temp_v == 0)
		v.push_back(0);
	while (temp_v) {
		int a = temp_v % 10;
		temp_v /= 10;
		v.push_back(a);
	}
	reverse(v.begin(), v.end());

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		prohibit_btn[a] = 1;
	}
	//100에서 시작하니까 버튼 안누르고 100에서 계산한것도 시작
	int ans = v.size();
	minV = abs(NUM - 100);	
	set_num(0, 0);
	int t1 = ans + minV;

	minV = abs(NUM - 100);
	int ans2 = v.size() + 1;
	set_num2(0, 0);
	int t2 = ans2 + minV;

	minV = abs(NUM - 100);
	if(v.size()>= 2)
		set_num3(0, 0);
	int ans3 = v.size() - 1;
	int t3 = ans3 + minV;

	int ff_num = min(t1, min(t2, t3));

	int start_100 = 987654321;
	start_100 = abs(100 - NUM);
	
	int f_num = min(ff_num, start_100);
	cout << f_num << '\n';

	return 0;
}
