#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPowerOfTwo(int n) {
    if(n <= 0)
        return false;
    return !(n & (n - 1));
}

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("Please input a number\n");
		return 0;
	}
	if(isPowerOfTwo(atoi(argv[1])))
		printf("true\n");
	else
		printf("false\n");

	return 0;
}