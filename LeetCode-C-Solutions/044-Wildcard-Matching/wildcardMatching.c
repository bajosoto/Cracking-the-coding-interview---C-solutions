#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isMatch(char* word, char* wild) {
    char *foundStar = NULL;
    char *lastWord = word;

    /* Repeat as long as we havent reached the end of the word */
    while(*word){
        /* If a match was found (finding a '?' counts as a match too) */
        if(*wild == '?' || *wild == *word){
            /* Increment both pointers. These ones have been cleared (for now, unless
             * we have to backtrack if a '*' is found) */
            wild++;
            word++;
        }
        /* If a star was found */
        else if(*wild== '*'){
            /* Save the location where the last star was found */
            foundStar = wild;
            /* Keep going forward to next character in wildcard word */
            wild++;
            /* Save the location of word last time a '*' was found. Whenever 
             * no matches or '*' are found after this, we will come back to the 
             * character after this position. */
            lastWord = word;
        }
        /* If there was no match, no '?', and no '*' found, but a star
         * had been previously found, try next time checking the position after
         * the location of the last star and the constantly incrementing lastWord
         * (the last position that was checked against the char after the '*') */
        else if(foundStar){
            wild = foundStar + 1;
            lastWord++;
            word = lastWord;
        }
        /* No matches found and no '*' found previously. The words are not matched. */
        else{
            return false;
        }
    }
    /* No mismatch so far and we reached the end of the original word. Now check the rest
     * of the characters in the wildcard word and make sure they are all '*'. Otherwise, 
     * it won't be a match. */
    while(*wild == '*')
        wild++;
    return !*wild;
}

int main(int argc, char *argv[]){
    if(argc < 3){
        printf("Please input two words.\n");
        return -1;
    }

    if(isMatch(argv[1], argv[2]))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}