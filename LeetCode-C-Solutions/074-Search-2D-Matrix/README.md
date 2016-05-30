# 74 - Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.  
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:
````
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
````
Given **target = 3**, return **true*.


**My answer:**
- Start at top right corner. 
- Go down if target is larger. 
- Go left if target smaller.
- Worst case O(n + m)

````c
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int row = 0;
    int col = matrixColSize - 1;
    bool ans = true;
    while(ans == true){
        if(target == matrix[row][col]){
            break;
        }
        else if(target < matrix[row][col]){
            if(col > 0)
                col--;
            else
                ans = false;            
        }
        else if(target > matrix[row][col]){
            if(row < matrixRowSize - 1)
                row++;
            else
                ans = false;
        }
    }
    
    return ans;
}
````

A more efficient solution is to use a binary search to find the row where the target is (or should be) and then another binary search on that row per column item to find if the target is there:
````c
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int r1 = 0;
    int r2 = matrixRowSize - 1;
    int c1 = 0;
    int c2 = matrixColSize - 1;
    int mid;

    if(matrix == NULL || matrixColSize == 0 || matrixRowSize == 0)
        return false;

    while(r1 < r2){
        mid = (r1 + r2) / 2;
        if(matrix[mid][c1] > target){
            r2 = mid - 1;
        }
        else if(matrix[mid][c1] < target){
            if(target <= matrix[mid][c2]){
                r1 = mid;
                break;
            }
            else
                r1 = mid + 1;
        }else{
            return true;
        }
    }
    while(c1 < c2){
        mid = (c1 + c2) / 2;
        if(matrix[r1][mid] > target){
            c2 = mid - 1;
        }
        else if(matrix[r1][mid] < target){
            c1 = mid + 1;
        }
        else{
            return true;
        }
    }
    return matrix[r1][c1] == target;
}
````