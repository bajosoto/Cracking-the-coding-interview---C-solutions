# 334. Reverse Vowels

Write a function that takes a string as input and reverse only the vowels of a string.

````
Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".
````

I implemented two solutions. One using a stack, and a more efficient one using indexes.

## Stack implementation
````c
char *reverseVowels(char *s) {
    Stack *stack = createStack();
    int length = strlen(s);
    int i;

    for(i = 0; i < length; i++){
        if(isVowel(s[i]))
            push(stack, s[i]);
    }
    for(i = 0; i < length; i++){
        if(isVowel(s[i]))
            s[i] = pop(stack);
    }
    return s;
}
````

## Index implementation
````c
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
````