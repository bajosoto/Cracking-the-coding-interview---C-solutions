#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VALID_LETTERS 60

int isPermutation(char *str1, char *str2){
 	int freq[MAX_VALID_LETTERS] = {0};
 	int length1 = strlen(str1);
 	int length2 = strlen(str2);
 	int i;	
 
	if(str1 == NULL || str2 == NULL)
 		return 0;
 	if(length1 != length2)
 		return 0;

 	for(i = 0; i < length1; i++){
 		freq[str1[i] - 'A']++;
 	}

 	for(i = 0; i < length2; i++){
 		freq[str2[i] - 'A']--;
 	}
 
 	for(i = 0; i < MAX_VALID_LETTERS; i++){
 		if(freq[i] != 0)
 			return 0;
 	}
 	return 1;
}

int main(int argc, char *argv[]){
 	char *str1, *str2;
 	if(argc > 2){
 		str1 = argv[1];
 		str2 = argv[2];
 		if(isPermutation(str1, str2)) 
 			printf("%s is a permutation of %s!\n", str1, str2);
 		else
 			printf("%s is not a permutation of %s :(\n", str1, str2);
 	}
 	return 0;
}
