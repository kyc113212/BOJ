#include <iostream>
#include <string>
#include <deque>
#include <cstring>

using namespace std;

int main() {

	string s;
	getline(cin, s);
	deque<char> d;

	string pre = "";
	int i = 0;
	for (i = 0; i < s.size(); i++) {
		if (s[i] >= 97 && s[i] <= 122) {
			pre += s[i];
		}
		else
			break;
	}

	string pre_var = "";
	for (int j = i; j < s.size(); j++) {
		if (s[j] != ' ')
			pre_var += s[j];
	}

	int a = 0;

	return 0;
}
