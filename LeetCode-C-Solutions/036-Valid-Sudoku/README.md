# 36 - Valid Sudoku

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example: 
````
1 2 . 4 5 6 7 8 9 
. . 1 . . . . . . 
3 . . . . . . . . 
4 . . . . . . . . 
5 . . . . . . . .  -> invalid sudoku
6 . . . . . . . . 
7 . . . . . . . . 
8 . . . . . . . . 
9 . . . . . . . . 
````

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

** My solution:**
- This problem can either be solved by checking each field once and using 3 9x9 arrays, or checking each field 3 times and using one 1x9 array. I solved it with the second method. Both are valid and each trade off speed vs memory.

````c
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
```