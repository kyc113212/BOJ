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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll arr[200001];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<ll> v;
	int N;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			arr[i] = v[i];
		}
		else
			arr[i] += arr[i - 1] + v[i];
	}

	ll minV = arr[v.size()-1] - arr[0]*v.size();
	ll ans = v[0];
	for (int i = 1; i < N; i++) {
		//값 계산
		ll temp_v = (i+1)*v[i] - arr[i] + (arr[v.size()-1] - arr[i]) - v[i]*(v.size() - i - 1);
		if (temp_v < minV) {
			ans = v[i];
			minV = min(minV, temp_v);
		}
	}

	cout << ans << '\n';

	// 누적합에서 각 값*index의 갯수만큼 뺴준다


	return 0;
}
