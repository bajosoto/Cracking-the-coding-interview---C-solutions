##isUnique 
Implement an algorithm to check if a string has all unique characters.

*8:37*

**Idea 1:** time:O(nlogn) space:O(1)
- Sort array
- Check char by char and see if next char is equal to last

**Idea 2:** time: O(n)  space: O(1)
- Use a bitfield to count each char's frequency

````c
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
````

*8:56*
