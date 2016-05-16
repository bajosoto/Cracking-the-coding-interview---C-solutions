## Palindrome Permutation
Write a function to check if a string is a permutation of a palindrome.

*22:40*

**Brute force:** time & space: O(n!)
- Calculate all possible permutations
- Check if one is a palindrome

**Idea 1:** time: O(n) space: O(1)
- Use a bitfield representing each possible character (assuming only alphabetic characters)
- Read char by char, switching the corresponding position in the bitfield
- In the end, only one of the bits should be 1

````c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int permutationIsPalindrome(char *str){
 	uint64_t bitfield = 0;
 	int length = strlen(str);
 	int i;

 	if(str == NULL){
		return -1;
 	}else{
   	for(i = 0; i < length; i++){
 			bitfield ^= 1 << (str[i] - 'A');
 		}
 		if(((bitfield) & (bitfield - 1)) == 0)
 			return 1;
 		else
 			return 0;				
 	}
}

int main(int argc, char *argv[]){
 	if(argc > 1){
 		if(permutationIsPalindrome(argv[1]))
 			printf("Some permutation of %s is a palindrome!\n", argv[1]);
 		else
 			printf("No permutation of %s is a palindrome...\n", argv[1]);
 	}
 	return 0;
}
````

*22:51*
