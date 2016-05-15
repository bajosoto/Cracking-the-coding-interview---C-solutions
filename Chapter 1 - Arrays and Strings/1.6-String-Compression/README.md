## String Compression

Implement a method to perform basic string compression using the counts of repeated characters. Return the shortest between the compressed and the original.
````
Ex. 

aaabbbc = a3b3c1
abcdd = (a1b2c3d2) abcdd
````
*9:30*

**Idea 1:**
- I will implement a function that pushes characters and numbers (even longer than one character e.g. '15' into an empty string)
- The main function will count repeated characters and as soon as a different one is found, it will call this helper function.
- The empty character array needs not to be dynamic, since as soon as we fill it with numbers and characters, this will mean the original one was shorter.

````c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compHelper(char *str, int count, char letter, int offset, int length);
char *strCompress(char *str);
int decimalPlaces(int count);

char *strCompress(char *str){
 	int count = 1;
 	int indexOffset = 0;
 	char *buffer;
	int i;
 	int length = strlen(str);
 	char current;

 	if(str == NULL)
 		return NULL;
 	
 	current = str[0];
 	buffer = (char *)malloc(sizeof(char) * length + 1);

 	for(i = 1; i < length; i++){
 		if(str[i] != current){
 			if(!compHelper(buffer, count, current, indexOffset, length))
 				// Buffer is already longer than original
 				return str;
 			current = str[i];
 			indexOffset += decimalPlaces(count) + 1; 
 			count = 1;
 		}else{
 			count++;
 		}

 		if(i == length - 1){
 			if(!compHelper(buffer, count, current, indexOffset, length))
 				// Buffer is already longer than original
 				return str;
 		}
 	}
 	return buffer;
}

int decimalPlaces(int count){
 	int decimals = 1;
 	int num = count;
	while(num / 10 > 0){
 		decimals++;
		num = num/10;
 	}
 	return decimals;
}

int compHelper(char *str, int count, char letter, int offset, int length){
 	if(offset + decimalPlaces(count) + 1 >= length)
		return 0;
 	str[offset++] = letter;
 	do{
 		str[offset++] = '0' + count % 10;
 		count /= 10;
 	}while(count > 0);
 	str[offset] = '\0';
 	return 1;
}

int main(int argc, char *argv[]){
 	if(argc < 2)
		return -1;
 	char *compressed = strCompress(argv[1]);
 	printf("Original string: \t%s\n", argv[1]);
 	printf("Compressed string: \t%s\n", compressed);
 	free(compressed);
 	return 0;
}
````
*10:24*
