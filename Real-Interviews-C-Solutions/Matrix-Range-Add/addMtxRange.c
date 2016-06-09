#include <stdio.h>
#include <stdlib.h>

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
	/* Allocate and populate a 2D array */
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

    /* Request ranges from user */
    printMatrix(mat, 4, 5);
    printf("r1: ");
    scanf("%d", &r1);
    printf("c1: ");
    scanf("%d", &c1);
    printf("r2: ");
    scanf("%d", &r2);
    printf("c2: ");
    scanf("%d", &c2);

    /* Perform sum with first method */
    int ans = addMtxRange(mat, c1, r1, c2, r2, 4, 5);
    if(ans >= 0)
    	printf("METHOD 1: ans = %d\n", ans);
    else
    	printf("METHOD 1: ans = ERROR\n");

    /* Perform sum with second method */
    int **preCalcdBuff = fastAddMtxRangeInit(mat, 4, 5);
    ans = fastAddMtxRange(preCalcdBuff, c1, r1, c2, r2, 4, 5);  
    if(ans >= 0)
    	printf("METHOD 2: ans = %d\n", ans);
    else
    	printf("METHOD 2: ans = ERROR\n");	return 0;
}

