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
int addMtxRange(int **matrix, int c1, int r1, int c2, int r2, int maxRows, int maxCols){
    int sum = 0;
    int minC = min(c1, c2);
    int maxC = max(c1, c2);
    int minR = min(r1, r2);
    int maxR = max(r1, r2);

    /* Safety check */
    if(maxC >= maxCols || maxR >= maxRows){
        // Report some error
        printf("(%d, %d) is out of range.\n", maxR, maxC);
        return -1;
    }

    for(int r = minR; r <= maxR; r++)
        for(int c = minC; c <= maxC; c++)
            sum += matrix[r][c];

    return sum;
}
````

- Complexity:
    + time: O(N x M), where N and M are the dimensions of the matrix
    + space: O(1)

## Follow up
What if this matrix had a million entries, and the add function will be called a million times. Is there any way to reduce time complexity?

**My solution:**
- Pre-calculate all sums from the point (0,0) to all other points and store them in a 2D array SUM.
- To calculate the sum between points (r1, c1) and (r2, c2), compute the following: 
 
````
+ SUM(max(r1, r2)    , max(c1, c2)    ) 
- SUM(min(r1, r2) - 1, max(c1, c2)    )
- SUM(max(r1, r2)    , min(c1, c2) - 1) 
+ SUM(min(r1, r2) - 1, min(c1, c2) - 1)
---------------------------------------
                           = ans
````

Pre-calculation function:
````c
/* Returns a 2D array with all precalculated sums from range (0,0) to all other coordinates */
int **fastAddMtxRangeInit(int **matrix, int maxRows, int maxCols){
    // Create 2D matrix to store precalculated values
    int **preCalcd = (int **)malloc(sizeof(int *) * maxRows);
    for(int i = 0; i < maxRows; i++)
        preCalcd[i] = (int *)malloc(sizeof(int) * maxCols);

    for(int i = 0; i < maxRows; i++)
        for(int j = 0; j < maxCols; j++){
            preCalcd[i][j] = addMtxRange(matrix, 0, 0, j, i, maxRows, maxCols);
        }
    return preCalcd;
}
````

Sum calculation using pre-calculations:
````c
int fastAddMtxRange(int **preCalcd, int c1, int r1, int c2, int r2, int maxRows, int maxCols){
    int sum = 0;
    int minC = min(c1, c2);
    int maxC = max(c1, c2);
    int minR = min(r1, r2);
    int maxR = max(r1, r2);

    /* Safety check */
    if(maxC >= maxCols || maxR >= maxRows){
        // Report some error
        printf("(%d, %d) is out of range.\n", maxR, maxC);
        return -1;
    }

    int largeArea = preCalcd[maxR][maxC];
    int smallArea = (minR == 0 || minC == 0) ? 0 : preCalcd[minR - 1][minC - 1];
    int verticalRect = (minC == 0) ? 0 : preCalcd[maxR][minC - 1];
    int horizRect = (minR == 0) ? 0 : preCalcd[minR - 1][maxC];

    sum = largeArea + smallArea - verticalRect - horizRect;
    return sum; 
}
````

Sample output:
````
addMtxRange.exe
| 1 3 5 7 8 |
| 3 7 3 6 2 |
| 5 9 2 5 7 |
| 9 3 5 6 1 |
r1: 3
c1: 4
r2: 2
c2: 3
METHOD 1: ans = 19
METHOD 2: ans = 19

addMtxRange.exe
| 1 3 5 7 8 |
| 3 7 3 6 2 |
| 5 9 2 5 7 |
| 9 3 5 6 1 |
r1: 0
c1: 0
r2: 3
c2: 4
METHOD 1: ans = 97
METHOD 2: ans = 97
````