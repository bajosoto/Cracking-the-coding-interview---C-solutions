#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "LinkedList.h"

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    LinkedList_t *list = createList();
    
    int currLineLength = 0;
    int numLinesCtr = 0;
    bool firstWordInLine = true;
    
    /* Calculate number of Lines needed (numLinesCtr) */
    for(int i = 0; i < wordsSize; i++){
        if(firstWordInLine){
            currLineLength += strlen(words[i]);
            firstWordInLine = false;
            numLinesCtr++;
            createNodeAtTail(list, 1);
        }
        else{
            if(maxWidth - currLineLength >= strlen(words[i]) + 1){
                currLineLength += (strlen(words[i]) + 1);
                list->tail->data++;
            }
            else{
                firstWordInLine = true;
                i--;
                currLineLength = 0;
            }
        }
    }
    
    /* Allocate memory for string array and set returnSize for output */
    char **lines = (char **)malloc(sizeof(char *) * numLinesCtr);
    *returnSize = numLinesCtr;
    
    /* Global word index */
    int wordIndex = 0;
    
    /* Create lines one by one*/
    for(int i = 0; i < numLinesCtr; i++){
        /* Allocate memory for line */
        lines[i] = (char *)malloc(sizeof(char) * maxWidth + 1); // Including null terminator
        memset(lines[i], '\0', sizeof(char) * maxWidth + 1);
        
        /* fetch number of words in this line from the LL acting as a queue */
        int numWordsInCurrLine = list->head->data;
        list->head = list->head->next;
        
        /* Add length of words in current line */
        int lengthOfWordsInCurrLine = 0;
        for(int j = 0; j < numWordsInCurrLine; j++){
            lengthOfWordsInCurrLine += strlen(words[wordIndex + j]);
        }
        
        /* number of space "fields" between words */
        int spaceFieldsInCurrLine = numWordsInCurrLine - 1;
        /* number of space characters in line*/
        int spacesInCurrLine = maxWidth - lengthOfWordsInCurrLine;
        /* Number of space characters per spacefield (assuming even spacing between words)*/
        int spaceFieldSize = spacesInCurrLine / spaceFieldsInCurrLine;
        /* Number of spacefields that will be 1 space char longer */
        int longSpaceFields = spacesInCurrLine - spaceFieldSize * spaceFieldsInCurrLine;
        
        /* Add words and spaces */
        for(int j = 0; j < numWordsInCurrLine; j++){
            /* Add first word without spaces */
            if(j == 0){
                /* global word index is being updated here */
                strcpy(lines[i], words[wordIndex++]);
            }
            else{
                /* Last Line */
                if(i == numLinesCtr - 1){
                    strcat(lines[i], " ");
                    strcat(lines[i], words[wordIndex++]);
                }
                else if(longSpaceFields){
                    longSpaceFields--;
                    /* Add spaces + 1 since this spacefield is one of the ones 
                    ** to the left with extra characters */
                    for(int k = 0; k < spaceFieldSize + 1; k++)
                        strcat(lines[i], " ");
                    /* global word index is being updated here */
                    strcat(lines[i], words[wordIndex++]);
                }
                else{
                    /* Add spaces */
                    for(int k = 0; k < spaceFieldSize; k++)
                        strcat(lines[i], " ");
                    /* global word index is being updated here */
                    strcat(lines[i], words[wordIndex++]);                   
                }
            }
        }
    }
    
    return lines;
}

void printArrayOfStrings(char **arr, int numStrings){
    for(int i = 0; i < numStrings; i++){
        printf("%s\n", arr[i]);
    }
}

int main(){
    char *words[100] = {"Lorem","ipsum","dolor","sit","amet,","consectetur","adipiscing","elit.","Mauris",
    "ullamcorper","id","nisi","a","ultricies.","Fusce","hendrerit","velit","non","justo","condimentum,",
    "eget","auctor","tellus","euismod.","Praesent","rutrum","massa","tortor,","eget","commodo","metus",
    "dignissim","eget.","Cras","aliquam","venenatis","ex","non","dignissim.","Donec","lacus","dolor,",
    "tincidunt","non","varius","ut,","volutpat","id","tellus.","Nullam","commodo","ultricies","aliquam.",
    "Praesent","eu","elit","suscipit,","luctus","libero","in,","hendrerit","odio.","Aliquam","erat",
    "volutpat.","Donec","gravida","tincidunt","arcu,","non","lobortis","dui","pharetra","ac.","Donec",
    "at","odio","quis","ante","imperdiet","molestie","a","eget","sem.","Ut","pretium,","magna","sit",
    "amet","maximus","mattis,","odio","lacus","pellentesque","urna,","in","eleifend","purus","est","at."};
    char **strings = (char **)malloc(sizeof(char *) * 100);
    int *numberOfLines = (int *)malloc(sizeof(int));

    for(int i = 0; i < 100; i++){
        strings[i] = words[i];
    }

    printArrayOfStrings(fullJustify(strings, 100, 75, numberOfLines), *numberOfLines);
    return 0;
}