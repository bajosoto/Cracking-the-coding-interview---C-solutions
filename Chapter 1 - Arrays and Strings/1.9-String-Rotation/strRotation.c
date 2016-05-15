#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int isSubstring(char *shortStr, char *longStr);
int strRotation(char *s1, char *s2);
char *strDuplicate(char *str);

char *strDuplicate(char *in){
 	int i;
 	int length = strlen(in);
 	char *out = (char *)malloc(sizeof(char) * (length * 2 + 1));
 	for(i = 0; i < length; i++){
 		out[i] = in[i];
 		out[i + length] = in[i];
 	}
 	out[length * 2] = '\0';
 	return out;
}

int strRotation(char *s1, char *s2){
 	char *dupS2;
 	int res;

 	if(s1 == NULL && s2 == NULL)
 		return -1;
 	if(strlen(s1) != strlen(s2))
 		return 0;
 	
 	dupS2 = strDuplicate(s2);

 	if(isSubstring(s1, dupS2))
 		res = 1;
 	else
 		res = 0;

  	free(dupS2);
 
 	return res;
}

int isSubstring(char *shortStr, char *longStr){
 	return strstr(longStr, shortStr) == NULL ? 0 : 1;
}

int main(int argc, char *argv[]){
 	if(argc < 3)
 		return -1;
 	if(strRotation(argv[1], argv[2]))
 		printf("%s is a string rotation of %s.\n", argv[1], argv[2]);
 	else
 		printf("%s is not a string rotation of %s.\n", argv[1], argv[2]);
 	return 0;
}
