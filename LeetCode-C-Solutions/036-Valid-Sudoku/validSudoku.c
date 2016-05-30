#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printSudoku(char **arr){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}


void clearArray(char *arr){
    int i;
    for(i = 0; i < 9; i++)
        arr[i] = '.';
}

void pushChar(char *arr, char num){
    arr[num - 1 - '0'] = num;
}

char getChar(char *arr, char num){
	return arr[num - 1 - '0'];
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    char arr[9];
    
    // Check horizontally
    for(int i = 0; i < boardRowSize; i++){
    	clearArray(arr);
    	for(int j = 0; j < boardColSize; j++){
    		if(board[i][j] != '.'){
    			if(getChar(arr, board[i][j]) == board[i][j])
    				return false;
    			else
    				pushChar(arr, board[i][j]);
    		}
    	}
    }

    // Check vertically
    for(int j = 0; j < boardColSize; j++){
    	clearArray(arr);
    	for(int i = 0; i < boardRowSize; i++){
    		if(board[i][j] != '.'){
    			if(getChar(arr, board[i][j]) == board[i][j])
    				return false;
    			else
    				pushChar(arr, board[i][j]);
    		}
    	}
    }

    // Check squares
    for(int i = 0; i < 3; i++){
    	for(int j = 0; j < 3; j++){
    		clearArray(arr);
    		for(int k = 0; k < 3; k++){
    			for(int l = 0; l < 3; l++){
     				if(board[i * 3 + k][j * 3 + l] != '.'){
    					if(getChar(arr, board[i * 3 + k][j * 3 + l]) == board[i * 3 + k][j * 3 + l])
    						return false;
    					else
    						pushChar(arr, board[i * 3 + k][j * 3 + l]);   
					}   
    			}
    		} 				    						
    	}
    }
    return true;
}

int main(){
	char nums[9][9] = {
		 			  {'1', '2', '.', '4', '5', '6', '7', '8', '9'},
		 			  {'.', '.', '1', '.', '.', '.', '.', '.', '.'},
		 			  {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
		 			  {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
		 			  {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
		 			  {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
		 			  {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
		 			  {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
		 			  {'9', '.', '.', '.', '.', '.', '.', '.', '.'}
		 			};
	char *sudoku[9];
	for(int i = 0; i < 9; i++){
		sudoku[i] = (char *)malloc(sizeof(char) * 9);
		for(int j = 0; j < 9; j++){
			sudoku[i][j] = nums[i][j];
		}
	}
	
	printSudoku(sudoku);
	if(isValidSudoku(sudoku, 9, 9))
		printf("VALID\n");
	else
		printf("INVALID\n");

	return 0;
}