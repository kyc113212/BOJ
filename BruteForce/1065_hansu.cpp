#include <stdio.h>
#include <math.h>

int han(int n){
	
	int result;
	int cnt = 99;
	int sub1, sub2;
	int i;
	int a, b, c;
	int temp;

	if (n < 100)
		result = n;
	else if (n >= 100){
		for (i = 100; i <= n; i++){
			temp = i;
			a = temp % 10;
			temp = temp / 10;
			b = temp % 10;
			temp = temp / 10;
			c = temp;
			sub1 = c - b;
			sub2 = b - a;
			if (sub1 == sub2)
				cnt++;
		}
		result = cnt;
	}

	//printf("%d %d %d %d %d\n", c, b, a,sub1,sub2);

	return result;
}

int main(){

	int num;
	scanf("%d", &num);
	if ((num < 0) && (num>1000))
		return 0;

	printf("%d\n", han(num));

	return 0;
}
