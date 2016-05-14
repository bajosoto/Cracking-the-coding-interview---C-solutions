## Zero Matrix

Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to zero. Do not use additional storage.

*5:45*

**Idea 1:** 
- Run through the whole matrix
- When a 0 is found, set both a[0][x] and a[y][0] to zero to reuse the same arrays and achieve no additional used space
- Run first row and set zeroes in all columns where a 0 was found.
- Do the same for the first column

`````c
#include <stdio.h>
#include <stdlib.h>

int **zeroMatrix(int **matrix, int length, int height){
 	int i, j;
 	int firstCol = 0, firstRow = 0;
 	if(matrix == NULL)
 		return NULL;
 
 	// Check first row and first col for zeroes
 	for(i = 0; i < height; i++){
 		if(matrix[i][0] == 0){
 			firstCol = 1;
 			break;
 		}
 	}
  	for(j = 0; j < length; j++){
 		if(matrix[0][j] == 0){
 			firstRow = 1;
 			break;
 		}
 	}

 	// Mark first column and row if a 0 is found
 	for(i = 1; i < height; i++){
 		for(j = 1; j < length; j++){
 			if(matrix[i][j] == 0){
 			 	matrix[i][0] = 0;
 			 	matrix[0][j] = 0;
 			}
 		}
 	}

 	// Clear rows
 	for(i = 1; i < height; i++){
 		if(matrix[i][0] == 0){
 			for(j = 0; j < length; j++){
 				matrix[i][j] = 0;
 			}
 		}
 	}

 	// Clear cols
 	for(j = 1; j < length; j++){
 		if(matrix[0][j] == 0){
 			for(i = 0; i < height; i++){
 				matrix[i][j] = 0;
 			}
 		}
 	}

 	// Clear first column and/or row
 	if(firstRow)
 		for(j = 0; j < length; j++)
 			matrix[0][j] = 0;
  	if(firstCol)
 		for(i = 0; i < height; i++)
 			matrix[i][0] = 0;
 	

 	return matrix;
}

void printMatrix(int **matrix, int length, int height){
 	int i, j;

 	if(matrix == NULL)
 		 return;

 	for(i = 0; i < height; i++){
 		for(j = 0; j < length; j++){
 			printf("%d ", matrix[i][j]);
 		}
 		printf("\n");
 	}
 	printf("\n");
}

int main(int argc, char *argv[]){
	int i, j = 0;
 	int mat[15][15] = {	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 						{1,1,1,1,1,1,1,1,1,1,1,0,1,1,1},
 						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 						{1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
 						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 						{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
 						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 						};
 	
 	// Create array in heap and copy test matrix into it
 	int **matrix = (int **)malloc(sizeof(int *) * 15);
 	for(i = 0; i < 15; i++){
 		matrix[i] = (int *)malloc(sizeof(int) * 15);
 	}
 	for(i = 0; i < 15; i++)
 		for(j = 0; j < 15; j++)
 			matrix[i][j] = mat[i][j];

 	printMatrix(matrix, 15, 15);
 	matrix = zeroMatrix(matrix, 15, 15);
 	printMatrix(matrix, 15, 15);

 	return 0;
}

````
*6:25*
