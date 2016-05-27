#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int isVowel(char letter){
    if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ||
       letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U')
        return 1;
    else
        return 0;
}

char *reverseVowels(char *s) {
    int length = strlen(s);
    int index_1 = 0;
    int index_2 = length - 1;
    char temp;

    while(index_1 < index_2){
        while(!isVowel(s[index_1]) && index_1 != index_2){
            index_1++;
        }
        while(!isVowel(s[index_2]) && index_1 != index_2){
            index_2--;
        }
        
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
    printf("reversed: %s\n", reverseVowels(argv[1]));
    return 0;
}