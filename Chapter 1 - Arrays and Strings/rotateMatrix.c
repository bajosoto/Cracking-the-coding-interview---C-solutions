#include <stdio.h>
#include <stdlib.h>

char **rotateMatrixHelper(char **matrix, int lenght);
char **rotateMatrix(char **matrix, int lenght, int height);
void printMatrix(char **matrix, int height, int lenght);

char **rotateMatrix(char **matrix, int lenght, int height){
	if(matrix == NULL || lenght != height)
 		return matrix; 	
 	return rotateMatrixHelper(matrix, lenght);
}

char **rotateMatrixHelper(char **matrix, int lenght){
 	char temp;
 	int i, j = 0;
 	int layer = 0;
  	for(layer = 0; layer < lenght / 2; layer++){
 		for(i = layer; i < lenght - layer - 1; i++){
 			// Store right
 			temp = matrix[i][lenght - 1 - layer];   		
 			// Top to right
 			matrix[i][lenght - layer - 1] = matrix[layer][i];
 			// Left to top
 			matrix[layer][i] = matrix[lenght - 1 - i][layer];
 			// Bottom to left
 			matrix[lenght - 1 - i][layer] = matrix[lenght - 1 - layer][lenght - 1 - i];
 			// Right to bottom
 			matrix[lenght - 1 - layer][lenght - 1 - i] = temp;
 		}
 	}
 	return matrix;
}

void printMatrix(char **matrix, int height, int lenght){
 	int i, j = 0;

 	if(matrix == NULL)
 		return; 	
 	
 	for(i = 0; i < height; i++){
 		for(j = 0; j < lenght; j++){
 			printf("%c ", matrix[i][j]);
 		}
 		printf("\n");
 	}
 	printf("\n");
}

int main(int argc, char *argv[]){
	int i, j;

	// Test array
 	char mat[5][5] =    {{'+', '+', '^', 'o', 'o'},
 						 {'+', '+', '^', 'o', 'o'},
 						 {'[', '[', '-', ']', ']'},
 						 {'@', '@', 'v', '*', '*'},
 						 {'@', '@', 'v', '*', '*'}};

 	// Create array in heap and copy test array into it
 	char **matrix = (char **)malloc(sizeof(char *) * 5);
 	for (i = 0; i < 5; i++)
         matrix[i] = (char *)malloc(5 * sizeof(char));
 	for(i = 0; i < 5; i++)
 		 for(j = 0; j < 5; j++)
 		 	matrix[i][j] = mat[i][j];

 	printMatrix(matrix, 5, 5);
 	char **rotatedMatrix = rotateMatrix((char **)matrix, 5, 5);
 	printMatrix(rotatedMatrix, 5, 5);
 	return 0;
}