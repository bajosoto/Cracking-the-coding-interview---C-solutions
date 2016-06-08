#include <stdio.h>
#include <stdlib.h>

int addMtxRange(int **matrix, int c1, int r1, int c2, int r2, int maxRows, int maxCols){
	int sum = 0;
	int minC = min(c1, c2);
	int maxC = max(c1, c2);
	int minR = min(r1, r2);
	int maxR = max(r1, r2);

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

void fastAddMtxRangeInit(int **matrix, int **preCalcd, int maxRows, int maxCols){
	for(int i = 0; i < maxCols; i++)
		for(int j = 0; j < maxRows; j++)
			dest[i][j] = addMtxRange(matrix, 0, 0, i, j);
}

int fastAddMtxRange(int **preCalcd, int c1, int r1, int c2, int r2, int maxRows, int maxCols){

}

void printMatrix(int **matrix, int maxR, int maxC){
	for(int i = 0; i < maxR; i++){
		printf("| ");
		for(int j = 0; j < maxC; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("|\n");
	}
}

int main(int argc, char *argv[]){
	int matrix[4][5] = {{ 1, 3, 5, 7, 8 },
     					{ 3, 7, 3, 6, 2 },
     					{ 5, 9, 2, 5, 7 },
     					{ 9, 3, 5, 6, 1 }};
    int **mat = (int **)malloc(sizeof(int *) * 4);
    for(int i = 0; i < 4; i++){
    	mat[i] = (int *)malloc(sizeof(int) * 5);
    	for(int j = 0; j < 5; j++)
    		mat[i][j] = matrix[i][j];
    }

    int c1;
    int c2;
    int r1;
    int r2;

    printMatrix(mat, 4, 5);
    printf("r1: ");
    scanf("%d", &r1);
    printf("c1: ");
    scanf("%d", &c1);
    printf("r2: ");
    scanf("%d", &r2);
    printf("c2: ");
    scanf("%d", &c2);

    int ans = addMtxRange(mat, c1, r1, c2, r2, 4, 5);
    if(ans >= 0)
    	printf("ans = %d\n", ans);
    else
    	printf("ans = ERROR\n");
	return 0;
}

