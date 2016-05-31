#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int lengthOfLastWord(char* s) {
    int cnt = 0;
    int tmp = 0;
    bool newWord = false;
    while(*s){
        if(*s != ' '){
            newWord = true;
            cnt++;
        }
        else{
            if(newWord)
                tmp = cnt;
            newWord = false;
            cnt = 0;
        }
        s++;
    }
    return cnt == 0 ? tmp : cnt;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Please input a string...\n");
        return -1;
    }
    printf("The length of the last word is: %d\n", lengthOfLastWord(argv[1]));

    return 0;
}