# 58 - Length of Last Word 

Difficulty: Easy

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

````
For example, 
Given s = "Hello World",
return 5.
````

**My solution:**
- Gotchas:
    + Watch for spaces after last word.
    + Keep track of last length until a new one begins.

````c
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
````

Sample output:
````
Sergio$ ./lengthOfLastWord "Hello World"
The length of the last word is: 5
Sergio$ ./lengthOfLastWord "Lorem Ipsum blabla sit amet   "
The length of the last word is: 4
````
