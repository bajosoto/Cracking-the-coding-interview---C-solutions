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
 	int length = strlen(str);
 	for(i = 0; i < length; i++){
 		if(str[i] == ' ')
 			spaceCnt++;
 	} 
 	return spaceCnt;
}

char *urlify(char *str){
 	char *longStr = createHelper(str);
 	int i;
 	int length = strlen(str);
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

int main(int argc,char *argv[]){
  	char *myStr;
 	if(argc < 1){
 		return -1;
 	}else{
 		myStr = urlify(argv[1]);
 		printf("Original: %s\n", argv[1]);
		printf("URLified: %s\n", myStr);
 		free(myStr);
 	}
 	return 0;
}
