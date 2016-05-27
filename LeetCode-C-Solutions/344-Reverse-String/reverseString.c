#include <stdio.h>
#include <string.h>

char* reverseString(char* s) {
    int length = strlen(s);
    int index_1 = 0;
    int index_2 = length - 1;
    char temp;

    while(index_1 < index_2){
    	temp = s[index_1];
        s[index_1] = s[index_2];
    	s[index_2] = temp;

    	index_1++;
    	index_2--;
    }
    return s;
}


int main(int argc, char *argv[]){
    if(argc < 2)
        return -1;
    printf("original: %s\n", argv[1]);
    printf("reversed: %s\n", reverseString(argv[1]));
    return 0;
}