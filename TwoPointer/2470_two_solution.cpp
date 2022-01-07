#include <iostream>
#include <algorithm>

using namespace std;

#define INF 987654321

int arr[100005];  
int N;

int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	int st = 0;
	int ed = N - 1;
	int sum = abs(arr[st] + arr[ed]);
	int minst = arr[st];
	int maxed = arr[ed];

	while (st < ed) {
		int t1 = abs(arr[ed - 1] + arr[st]);
		int t2 = abs(arr[ed] + arr[st + 1]);
		
		//값 비교후 차이 적은걸로 ed나 st조정
		//최종 sum값이랑 비교해서 더 작은게 있으면 그 값과 인덱스 갱신
		if (t1 < t2) {
			ed--;
			if (st >= ed)
				break;
			if (sum > t1) {
				minst = arr[st];
				maxed = arr[ed];
				sum = t1;
			}
		}
		else if(t1 > t2) {
			st++;
			if (st >= ed)
				break;
			if (sum > t2) {
				minst = arr[st];
				maxed = arr[ed];
				sum = t2;
			}
		}
		else {
			st++;
			ed--;
			if (st >= ed)
				break;
			if (sum > t2) {
				minst = arr[st];
				maxed = arr[ed];
				sum = t2;
			}
		}

	}

	cout << minst << " " << maxed << '\n';

	return 0;
}
