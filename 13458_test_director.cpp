	#include <iostream>
	#include <vector>

	using namespace std;

	int main() {

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		long long N;
		vector<long long> v;
		int B, C;
		long long ans = 0;

		cin >> N;
		for (long long i = 0; i < N; i++) {
			long long a;
			cin >> a;
			v.push_back(a);
		}
		cin >> B >> C;

		for (long long i = 0; i < N; i++) {
			v[i] -= B;
			ans++;
		}

		for (long long i = 0; i < N; i++) {
			long long temp_v = v[i];
			long long temp_value = v[i];
			if (v[i] <= 0)
				continue;
			long long div_value = temp_v / C;
			long long mod_value = temp_v % C;
			if (mod_value == 0) {
				ans += div_value;
			}
			else {
				ans += div_value + 1;
			}
		}

		cout << ans << endl;

		return 0;
	}
