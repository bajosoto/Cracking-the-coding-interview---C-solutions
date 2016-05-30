# 29 - Divide two numbers

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

**My answer:**
- By shifting the divisor to the left, I can get how many times the divisor multiplied by 2<sup>n</sup> fits in the dividend.
	- Add this 2<sup>n</sup> to answer
- Do this recursively or iterative, substracting the reminder of the divident minus the 2<sup>n</sup> * divisor until the divisor is larger than the new divident.

By doing it this way, a time complexity of O(log*n*) is achieved, instead of O(*n*) by just substracting the divisor from the divident.

````c
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
````