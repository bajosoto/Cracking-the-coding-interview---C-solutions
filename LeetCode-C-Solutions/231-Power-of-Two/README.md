# 231 - Power of Two 

Difficulty: Easy

Given an integer, write a function to determine if it is a power of two.

**My solution:**
- Using a simple mathematical trick.
- Gotchas:
	- Boundary checks. Check for negative numbers too.

````c
bool isPowerOfTwo(int n) {
    if(n <= 0)
        return false;
    return !(n & (n - 1));
}
````

Sample output:

````
Sergio$ ./powerOfTwo 2
true
Sergio$ ./powerOfTwo 4
true
Sergio$ ./powerOfTwo -1
false
Sergio$ ./powerOfTwo 4294967296
false
Sergio$ ./powerOfTwo 7
false
````