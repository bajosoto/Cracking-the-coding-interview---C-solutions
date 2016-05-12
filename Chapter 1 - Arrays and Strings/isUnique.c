#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

int isUnique(char *str){
	uint64_t bitField = 0;
	int length = strlen(str);
	int i;

	if(str != NULL){
		for(i = 0; i < length; i++){
			if(bitField & (1 << (str[i]- '0')))
				return 0;
			else
    			bitField |= 1 << (str[i] - '0');
		}
		return 1;
	}
 	return -1;	
}

int main(int argc, char* argv[]){
	char *str;
 	if(argc > 1){
 		str = argv[1];
 		if(isUnique(str)) printf("%s is unique!\n", str);
 		else printf("%s is not unique :(\n", str);
	}
	return 0;
}