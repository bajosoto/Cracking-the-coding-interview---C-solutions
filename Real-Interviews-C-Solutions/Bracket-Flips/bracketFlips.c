#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bracketFlips(char *brackets){
	int flips = 0;
	int balance = 0;
	int length = strlen(brackets);
	int i;

	if(brackets == NULL)
		return -1;

	if(length % 2 != 0)
		return -1;

	for(i = 0; i < length; i++){
		if(brackets[i] == '{'){
			balance++;
		}
		else if(brackets[i] == '}'){
			if(balance <= 0){
				flips++;
				balance++;
			}
			else{
				balance--;
			}
		}
	}
	return flips + balance / 2;
}

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("Please provide a string with brackets.\n");
		return -1;
	}

	int flipsNeeded = bracketFlips(argv[1]);
	if(flipsNeeded == 0)
		printf("Brackets are balanced.\n");
	else if(flipsNeeded == -1)
		printf("Brackets cannot be balanced.\n");
	else
		printf("Need to flip %d brackets.\n", flipsNeeded);

	return 0;
}