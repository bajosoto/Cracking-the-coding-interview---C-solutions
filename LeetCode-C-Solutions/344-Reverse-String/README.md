# Reverse String

Write a function that takes a string as input and returns the string reversed.
````
Example:
Given s = "hello", return "olleh".
````

*11:16*

````c
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
````

*11:19*