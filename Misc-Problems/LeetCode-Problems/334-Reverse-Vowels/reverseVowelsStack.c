#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Stack{
    char *array;
    int index;
}Stack;

void push(Stack *stack, char letter){
    stack->array[stack->index] = letter;
    stack->index++;
}

char pop(Stack *stack){
    return stack->array[--stack->index];
}

Stack *createStack(){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->array = (char *)malloc(sizeof(char) * 1024);
    stack->index = 0;
    return stack;
}

int isVowel(char letter){
    if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
        return 1;
    else
        return 0;
}

char *reverseVowels(char *s) {
    Stack *stack = createStack();
    int length = strlen(s);
    int i;
    
    char *out = (char *)malloc(sizeof(char) * 1024); 

    for(i = 0; i < length; i++){
        if(isVowel(s[i]))
            push(stack, s[i]);
    }
    for(i = 0; i < length; i++){
        if(isVowel(s[i]))
            out[i] = pop(stack);
        else
            out[i] = s[i];
    }
    out[length] = '\0';
    return out;
}

int main(int argc, char *argv[]){
    printf("%s", reverseVowels(argv[1]));
    return 0;
}