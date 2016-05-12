## Check permutation 
Given two strings, check if one is a permutation of the other.

Ex. pedro, prdeo = true

*21:08*

**Brute force:** time & space: O(n!)
 - Calculate all permutations
 - Compare each against second string
 
**Idea 1:** time & space: O(n)
 - If different length = false
 - Use an array with the frequencies of letters in str1 (adding)
 - Substracting from array each letter from str2
 - If all slots in the array are at 0 = true

*21:28*
