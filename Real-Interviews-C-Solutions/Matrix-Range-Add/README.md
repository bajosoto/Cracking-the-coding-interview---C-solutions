# Matrix Range Add

Given a 2D array of integers and two indexes, return the result of adding all the elements within the specified range.

````
Example:

A = | 1, 3, 5, 7, 8 |
    | 3, 7, 3, 6, 2 |
    | 5, 9, 2, 5, 7 |
    | 9, 3, 5, 6, 1 |

Range: (1, 1) , (3, 4)

Result: 7 + 3 + 6 + 2 + 9 + 2 + 5 + 7 + 3 + 5 + 6 + 1 = 56
````

**My solution:**
- Simple approach: Two nested for loops.

````c

````

- Complexity:
    + time: O(N x M), where N and M are the dimensions of the matrix
    + space: O(1)

## Follow up
What if this matrix had a million entries, and the add function will be called a million times. Is there any way to reduce time complexity?

**My solution:**
- Pre-calculate all sums from the point (0,0) to all other points and store them in a 2D array SUM.
- To calculate the sum between points (r1, c1) and (r2, c2)
    + Compute: 
````
+ SUM(max(r1, r2)    , max(c1, c2)    ) 
- SUM(min(r1, r2) - 1, max(c1, c2)    )
- SUM(max(r1, r2)    , min(c1, c2) - 1) 
+ SUM(min(r1, r2) - 1, min(c1, c2) - 1)
---------------------------------------
                           = ans
````
