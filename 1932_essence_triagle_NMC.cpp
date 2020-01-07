#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
	
	int N;
	cin >> N;
	int arr[501][501];
	memset(arr,0,sizeof(arr));
	for(int i = 1; i<=N; i++) {
		for(int j = 1; j<=i; j++){
			cin >> arr[i][j];
		}
	}

	int maxV = 0;

	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=i; j++){
			if(j == 1) 
				arr[i][j] += arr[i-1][j];
			else if(i == j) 
				arr[i][j] += arr[i-1][j - 1];
			else {
				if(arr[i-1][j-1] < arr[i-1][j]){
					arr[i][j] += arr[i-1][j];
				}
				else {
					arr[i][j] += arr[i-1][j-1];
				}				
			}
			//cout << arr[i][j] << endl;
			maxV = max(maxV, arr[i][j]);
			
		}
	}

	cout << maxV << endl;

	return 0;
}
