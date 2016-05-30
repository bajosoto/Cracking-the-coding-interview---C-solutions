# 240 - Search a 2D Matrix II 

Difficulty: Medium  

Write an efficient algorithm that searches for a value in an m x n matrix. 

This matrix has the following properties:
- Integers in each row are sorted in ascending from left to right.
- Integers in each column are sorted in ascending from top to bottom.

For example,
````
Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.
Given target = 20, return false.
````
*21:01*
** My solution:**
- Start at top right corner
- Go left if target is smaller
- Go down if target is bigger

````c
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int row = 0;
    int col = matrixColSize - 1;

    bool ans = false;

    while(ans == false){
        if(matrix[row][col] > target){
            if(col > 0)
                col--;
            else
                break;
        }
        else if(matrix[row][col] < target){
            if(row < matrixRowSize - 1)
                row++;
            else
                break;
        }
        else{
            ans = true;
        }
    }

    return ans;
}
````

*21:15*