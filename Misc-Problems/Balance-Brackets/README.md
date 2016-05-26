# Bracket Flips

Write a function that return the amount of brackets in a string ('{' or '}') that would need to be flipped so that they would be balanced.

````
Ex. 
{{{{ = 2
{{}}}} = 1
}}{{ = 4
````

*15:13*

**Idea 1:**
- have two counters, *flips* and *balance*. 
    - *flips* holds the number of '{' brackets that have been marked as needed to be flipped. This applies to closing brackets that don't have a corresponding opening bracket preceding them (by looking at *balance*)
    - *balance* keeps track of the amount of '{'s and '}'s. If they were balanced (in quantity), *balance* would be zero.
- Go through each character
    + if it is a {
        * increment balance
    + if it is a }
        * if there was no preceding '{' that could match it (*balance* <= 0)
            - increment *flips*
            - increment *balance* (instead of decrementing, since we're swapping it for a '{' )
        * if there's a presceding '{'
            - decrement *balance*
- Since an outstanding balance would mean we had extra '{' brackets, the amount of them that we must flip is only half of them.
- return *flips* + *balance* / 2

````c
int balanceBrackets(char *brackets){
    int flips = 0;
    int balance = 0;
    int length = strlen(brackets);
    int i;

    if(brackets == NULL)
        return -1;

    if(length % 2 != 0)
        return -1;

    for(i = 0; i < length; i++){
        if(brackets[i] == '{'){
            balance++;
        }
        else if(brackets[i] == '}'){
            if(balance <= 0){
                flips++;
                balance++;
            }
            else{
                balance--;
            }
        }
    }
    return flips + balance / 2;
}
````

Time complexity: O(*n*)
Space compexity: O(1)

*15:27*