# 68. Text Justification 

Difficulty: Hard

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

````
For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
````

Note: Each word is guaranteed not to exceed L in length.

**My solution:**
- Nothing fancy, just a lot of code. Took me almost two hours :(
- Some very brilliant 20 line answers in C++ are found [here](https://leetcode.com/discuss/13610/share-my-concise-c-solution-less-than-20-lines). 

````c
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
````


My output exampe:
````
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris ullamcorper
id  nisi  a  ultricies.  Fusce  hendrerit velit non justo condimentum, eget
auctor  tellus  euismod.  Praesent  rutrum massa tortor, eget commodo metus
dignissim eget. Cras aliquam venenatis ex non dignissim. Donec lacus dolor,
tincidunt  non  varius  ut,  volutpat  id  tellus. Nullam commodo ultricies
aliquam.  Praesent  eu  elit  suscipit,  luctus  libero in, hendrerit odio.
Aliquam  erat  volutpat.  Donec  gravida  tincidunt  arcu, non lobortis dui
pharetra  ac.  Donec  at  odio  quis ante imperdiet molestie a eget sem. Ut
pretium,  magna  sit  amet maximus mattis, odio lacus pellentesque urna, in
eleifend purus est at.
````