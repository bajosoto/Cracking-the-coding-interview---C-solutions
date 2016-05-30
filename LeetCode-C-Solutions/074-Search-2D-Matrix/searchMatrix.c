#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int row = 0;
    int col = matrixColSize - 1;
    bool ans = true;

    while(ans == true){
        if(target == *((int *)matrix + row*matrixColSize + col)){
            break;
        }
        else if(target < *((int *)matrix + row*matrixColSize + col)){
            if(col > 0)
                col--;
            else
                ans = false;            
        }
        else if(target > *((int *)matrix + row*matrixColSize + col)){
            if(row < matrixRowSize - 1)
                row++;
            else
                ans = false;
        }
    }
    
    return ans;
}

bool binSearchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target){
    int r1 = 0;
    int r2 = matrixRowSize - 1;
    int c1 = 0;
    int c2 = matrixColSize - 1;
    int mid;

    if(matrix == NULL || matrixColSize == 0 || matrixRowSize == 0)
        return false;

    while(r1 < r2){
        mid = (r1 + r2) / 2;
        if(*((int *)matrix + mid*matrixColSize + c1) > target){
            r2 = mid - 1;
        }
        else if(*((int *)matrix + mid*matrixColSize + c1) < target){
            if(target <= *((int *)matrix + mid*matrixColSize + c2)){
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
        if(*((int *)matrix + r1*matrixColSize + mid) > target){
            c2 = mid - 1;
        }
        else if(*((int *)matrix + r1*matrixColSize + mid) < target){
            c1 = mid + 1;
        }
        else{
            return true;
        }
    }
    return *((int *)matrix + r1*matrixColSize + c1) == target;
}

int main(){
    int nums[3][4] = {{1, 2, 3, 4},
                      {10, 11, 13, 14},
                      {15, 16, 17, 19}};
    printf("O(n+m) search: \n");
    if(searchMatrix((int **)nums, 3, 4, 17))
        printf("true\n");
    else
        printf("false\n");
    printf("O(log n) search: \n");
    if(binSearchMatrix((int **)nums, 3, 4, 17))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}