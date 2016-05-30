#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int divide(int dividend, int divisor) {
	if((dividend == INT_MIN && divisor == -1) || divisor == 0)
		return INT_MAX;
	if(dividend == 0)
		return 0;

	int neg = ((dividend < 0) != (divisor < 0)) ? true : false;
	long dvd = labs(dividend);
	long div = labs(divisor);
	int ans = 0;

	if(div == 1){
		if(dividend > 0){
			return (neg == true) ? -dividend : dividend;
		}
		else{
			return (neg == true) ? dividend : -dividend;
		}
	}
	if(dvd < div)
		return 0;

	while(dvd >= div){
		long mult = 1;
		long tmp = div;
		while(dvd >= (tmp << 1)){
			mult <<= 1;
			tmp <<= 1;
		}
		ans += mult;
		dvd -= tmp;

	}
	return (neg == true) ? -ans : ans;
}

int main(int argc, char *argv[]){
	printf("%ld\n", LONG_MAX);
	if(argc < 3){
		printf("Please input two numbers as parameters...\n");
		return -1;
	}

	int dividend = atoi(argv[1]);
	int divisor = atoi(argv[2]);
	printf("%d / %d = %d\n", dividend, divisor, divide(dividend, divisor));

	return 0;
}