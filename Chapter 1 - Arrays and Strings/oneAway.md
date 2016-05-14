## One Away:

Given two strings, write a function to check if they are one edit away (erase, add, replace), or zero edits away.

Example:
pale, ple = true (erase)  
pale, palle = true (add)  
pale, pare = true (replace)  
pale, pale = true (same)  
pale, rake = false (two replaces away)  

*7:46*

**Idea one:** time: O(n), space: O(1)
- Check if strings are the same (else return false)
- Check if strings are one char different length (else return false)
- Check char by char, switching a flag on the first difference
- If any second difference, return false
- Return true

````c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int oneAway(char *strA, char *strB){
 	char *longer;
	char *shorter;
	int oneEdit = 0;
	int lengthA = strlen(strA);
	int lengthB = strlen(strB);
 	int i, j = 0;

 	if(strA == NULL || strB == NULL)
 		return -1;
	if(abs(lengthA - lengthB) > 1)
 		return 0;
	if(strcmp(strA, strB) == 0)
		return 1;
 	
 	longer = lengthA > lengthB ? strA : strB;
 	shorter = lengthA > lengthB ? strB : strA;

 	for(i = 0, j = 0; i < strlen(shorter); i++, j++){
 		if(shorter[i] != longer[j]){
			if(lengthB == lengthA){
 				if(!oneEdit)
 					oneEdit++;
 			 	else
 				 	return 0;
 			}else{
 				if(shorter[i] != longer[++j]){
 					return 0;
  				}else{
 					if(!oneEdit)
 						oneEdit++;
 					else
 						return 0;
 			 	}
 			}
 		}
 	}
 	return 1;
}

int main(int argc, char*argv[]){
 	if(argc < 3)
 		return 0;
 	if(oneAway(argv[1], argv[2])) 
 		printf("%s is one (or zero) edit(s) away from %s\n",argv[1], argv[2]);
	else
 		printf("%s is not one edit away from %s\n",argv[1], argv[2]);
 	return 0;
}
````

*8:16*
