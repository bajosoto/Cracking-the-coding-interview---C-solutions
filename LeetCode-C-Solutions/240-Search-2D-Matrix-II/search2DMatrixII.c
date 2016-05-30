#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


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

int main(){
    int nums[3][4] = {{1, 2, 3, 4},
                      {10, 11, 13, 14},
                      {15, 16, 17, 19}};
	int *array[3];
	for(int i = 0; i < 3; i++){
		array[i] = (int *)malloc(sizeof(int) * 4);
		for(int j = 0; j < 4; j++){
			array[i][j] = nums[i][j];
		}
	}    
    if(searchMatrix(array, 3, 4, 19))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
