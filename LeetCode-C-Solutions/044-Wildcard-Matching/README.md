# 44 - Wildcard matching

Difficulty: Hard

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).
````
The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
````

**My solution:**
- My solution was essentially very similar to [Yu Zhu's answer](http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html) including the checking for continuous '*'s at the end. It did however fail matching a word if there was a case where the character after the wildcard was different by more than one character.

````
For example:

word: abcdefdg
wild: abc*dg 
````
- Mine would return false because it would compare the character after the next 'd' found, which is an 'e' and it expected a 'g'. The right answer is true.
- Yu's answer leverages this by using a separate pointer to find a matching pattern after the '\*' (in the word), and another pointer to be able to come back to the '\*' in the wildcard.
- This is my answer in C after following Yu's approach:

````c
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
````

Some test runs:
````
Sergio$ ./wildcardMatching hello he*
true
Sergio$ ./wildcardMatching hello ?e***
true
Sergio$ ./wildcardMatching hello ?e*l
false
Sergio$ ./wildcardMatching hello ?e*lo
true
Sergio$ ./wildcardMatching abcdefgdt a*dt
true
````