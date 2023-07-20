#include <stdio.h>
#include <math.h>

int main(){

	int num;
	int num2 = 0;
	int cal = 0;
	int cnt = 0;
	int sum = 0;
	int first, second;
	int first1, second1;

	scanf("%d", &num);
	num2 = num;

	while (1){
		
		first = num / 10;
		second = num % 10;
		cal = first + second;

		first1 = cal / 10;
		second1 = cal % 10;
		num = (second * 10) + second1;
		//printf("%d\n", num);
		cnt++;
		if (num2 == num)
			break;
	}

	printf("%d", cnt);

	return 0;
}
