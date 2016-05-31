#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool canWinNim(int n) {
    return n % 4 != 0;
}

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("Please input a number\n");
		return 0;
	}
	if(canWinNim(atoi(argv[1])))
		printf("You could certainly win!\n");
	else
		printf("You have no chances of winning\n");

	return 0;
}