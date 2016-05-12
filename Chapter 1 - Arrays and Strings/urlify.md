## URLify
Replace spaces in a string with '%20'.


**Idea 1:** time: O(n) space: O(1)
- Copy char by char from original array to new one until first space is found
- When a space is found, increment space counter, write %20
- Chars after spaces will be shifted 2*spaces to the right

*21:57*

````c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int countSpaces(char *str);
char *urlify(char *str);
char *createHelper(char *str);

char *createHelper(char *str){
 	int spaceCnt = countSpaces(str);
 	int length = strlen(str);
 	char *bigStr = (char *)malloc(sizeof(char) * 
                                (length + 2 * spaceCnt) );
 	return bigStr;
}

int countSpaces(char *str){
 	int spaceCnt = 0;
 	int i;
 	for(i = 0; i < lenght; i++){
 		if(str[i] == ' ')
 			spaceCnt++;
 	} 
 	return spaceCnt;
}

char *urlify(char *str){
 	char *longStr = createHelper(str);
 	int i;
 	int lenght = strlen(str);
 	int spaceCnt = 0;
 	if(str == NULL){
		return NULL;
 	}else{
 		for(i = 0; i < length; i++)
		{
 			if(str[i] != ' '){
 				longStr[i + spaceCnt * 2] = str[i];
 			}else{ 
 				longStr[i + spaceCnt * 2] = '%';
 				longStr[i + spaceCnt * 2 + 1] = '2';
 				longStr[i + spaceCnt * 2 + 2] = '0';
 				spaceCnt++;
 			}
 		}
		return longStr; 
 	}
}

int main(int argc, argv[]){
  	char *myStr;
 	if(argc < 1){
 		return -1;
 	}else{
 		myStr = urlify(argv[1])
 		printf("Original: %s\n", str);
		printf("URLified: %s\n", myStr);
 		free(myStr);
 	}
 	return 0;
}
````

*22:13*


