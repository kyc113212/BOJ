#include <iostream>
#include <cstring>

using namespace std;

#define INF 10000005

int N;

int main() {

	cin >> N;
	int maxV = 0;
	int minV = INF;

	int sa, sb, sc;
	cin >> sa >> sb >> sc;

	int maxDP[3] = { sa,sb,sc };
	int minDP[3] = { sa,sb,sc };
	for (int i = 1; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int tmaxDP[3] = { 0,0,0 };
		int tminDP[3] = { INF,INF,INF };
		tmaxDP[0] = max(maxDP[0], maxDP[1]) + a;
		tmaxDP[1] = max(maxDP[0], max(maxDP[1], maxDP[2])) + b;
		tmaxDP[2] = max(maxDP[2], maxDP[1]) + c;

		tminDP[0] = min(minDP[0], minDP[1]) + a;
		tminDP[1] = min(minDP[0], min(minDP[1], minDP[2])) + b;
		tminDP[2] = min(minDP[2], minDP[1]) + c;

		memcpy(maxDP, tmaxDP, sizeof(maxDP));
		memcpy(minDP, tminDP, sizeof(minDP));
	}
	
	for (int i = 0; i < 3; i++) {
		maxV = max(maxV, maxDP[i]);
		minV = min(minV, minDP[i]);
	}

	cout << maxV << ' ' << minV << '\n';



	return 0;
}
