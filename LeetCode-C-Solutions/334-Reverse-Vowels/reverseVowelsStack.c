#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Stack{
    char array[1024];
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
    stack->index = 0;
    return stack;
}

int isVowel(char letter){
    if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ||
       letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U')
        return 1;
    else
        return 0;
}

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

int main(int argc, char *argv[]){
    if(argc < 2)
        return -1;
    printf("original: %s\n", argv[1]);
    printf("reversed: %s\n", reverseVowels(argv[1]));
    return 0;
}