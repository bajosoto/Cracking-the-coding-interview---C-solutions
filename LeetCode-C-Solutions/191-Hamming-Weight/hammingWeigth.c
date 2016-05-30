#include <stdio.h>
#include <stdlib.h>

int hammingWeight(uint32_t n) {
    int i;
    int count = 0;
    for(i = 0; i < 32; i++){
        if(n & 1)
            count++;
        n = n >> 1;
    }
    return count;
}

int main(int argc, char *argv[]){
	printf("%d\n", hammingWeight(atoi(argv[1])));
	return 0;
}