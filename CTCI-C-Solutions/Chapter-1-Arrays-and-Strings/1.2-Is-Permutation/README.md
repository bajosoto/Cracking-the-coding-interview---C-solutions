## Check permutation 
Given two strings, check if one is a permutation of the other.

Ex. pedro, prdeo = true

*21:08*

**Brute force:** time & space: O(n!)
 - Calculate all permutations
 - Compare each against second string
 
**Idea 1:** time & space: O(n)
 - If different length = false
 - Use an array with the frequencies of letters in str1 (adding)
 - Substracting from array each letter from str2
 - If all slots in the array are at 0 = true

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

*21:28*
