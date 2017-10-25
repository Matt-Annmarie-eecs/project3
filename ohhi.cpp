/**
 * ohhi.cpp
 *
 * EECS 183
 * Project 3: 0h h1
 * Fall 2017
 *
 * <#Name(s)#>
 * Matthew Waldeck, Ann-Marie Zheng
 * <#uniqname(s)#>
 * mwaldeck, annzheng
 *
 * <#A description of the project here#>
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"
#include "driver.h"

///////////////////////////////////////
// UTILITY FUNCTIONS //////////////////
///////////////////////////////////////

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    //will hold # of unknown squares
    int unknownSquares = 0;
    for(int row = 0; row < size; row++){
        
        for(int col = 0; col < size; col++){
            if (board[row][col] == 0){
                unknownSquares++;
            }
        }
    }
    
    return unknownSquares;
}


///////////////////////////////////////
// VALIDITY CHECKS ////////////////////
///////////////////////////////////////

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
   for (int i = 0; i < size - 2; i++){
        if ((board[row][i] == color) && (board[row][i + 1] == color) &&
            (board[row][i + 2] == color)){
            return false;
        }
    }
    return true;

}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    for (int i = 0; i < size - 2; i++){
        if ((board[i][col] == color) && (board[i + 1][col] == color) &&
            (board[i + 2][col] == color)){
            return false;
        }
    }
    return true;

}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++){
        if (!row_has_no_threes_of_color(board, size, i, RED) || !row_has_no_threes_of_color(board, size, i, BLUE)){
            return false;
        }
        if (!col_has_no_threes_of_color(board, size, i, RED) || !col_has_no_threes_of_color(board, size, i, BLUE)){
            return false;
        }
    }
    return true;
    
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
    for(int col = 0; col < size; col++){
        if(board[row1][col] != board[row2][col]){
            return true;
        }
    }
    
    return false;
}

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    
    for(int row = 0; row < size; row++){
        if(board[row][col1] != board[row][col2]){
            return true;
        }
    }
    
    

    return false;
}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // your code here
    for(int row1 = 0; row1 < size; row1++){
        for(int row2 = row1 + 1; row2 < size; row2++){
            if(!rows_are_different(board, size, row1, row2)){
                return false;
                
            }
        }
    }
    
    for(int col1 = 0; col1 < size; col1++){
        for(int col2 = col1 + 1; col2 < size; col2++){
            if(!cols_are_different(board, size, col1, col2)){
                return false;
                
            }
        }
    }
    
    
    return true;
}


///////////////////////////////////////
// SOLVING FUNCTIONS //////////////////
///////////////////////////////////////

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    
    for(int col = 0; col < size; col++){
        
        if(board[row][col] == UNKNOWN){
            if (col == 0){
                if (board[row][col + 1] == BLUE && board[row][col + 2] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                else if(board[row][col + 1] == RED &&
                        board[row][col + 2] == RED){
                    mark_square_as(board, size, row, col, BLUE, announce);
                }
            }
            else if (col == size - 1){
                if (board[row][col - 1] == BLUE && board[row][col - 2] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                else if(board[row][col - 1] == RED &&
                         board[row][col - 2] == RED){
                    mark_square_as(board, size, row, col, BLUE, announce);
                }

            }
            else {
                if (board[row][col + 1] == BLUE &&
                     board[row][col - 1] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                
                else if (board[row][col + 1] == RED &&
                          board[row][col - 1] == RED){
                    mark_square_as(board, size, row, col, BLUE, announce);
                }
                
                
                if (board[row][col - 1] == BLUE && board[row][col - 2] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                else if(board[row][col - 1] == RED &&
                         board[row][col - 2] == RED){
                    mark_square_as(board, size, row, col, BLUE, announce);
                }
                
                else if (board[row][col + 1] == BLUE &&
                          board[row][col + 2] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                else if(board[row][col + 1] == RED &&
                        board[row][col + 2] == RED){
                    mark_square_as(board, size, row, col, BLUE, announce);
                }

                
            }
            
            
        }
        
    }
    
    
}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    
    for(int row = 0; row < size; row++){
        
        if(board[row][col] == UNKNOWN){
            if (row == 0){
                if (board[row + 1][col] == BLUE && board[row + 2][col] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                else if(board[row + 1][col] == RED &&
                        board[row + 2][col] == RED){
                    mark_square_as(board, size, row, col, BLUE, announce);
                }
            }
            else if (row == size - 1){
                if (board[row - 1][col] == BLUE && board[row - 2][col] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                else if(board[row - 1][col] == RED &&
                        board[row - 2][col] == RED){
                    mark_square_as(board, size, row, col, BLUE, announce);
                }
                
            }
            else {
                if (board[row + 1][col] == BLUE &&
                    board[row - 1] [col] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                
                else if (board[row + 1][col] == RED &&
                         board[row - 1][col] == RED){
                    mark_square_as(board, size, row, col, BLUE, announce);
                }
                
                
                if (board[row - 1][col] == BLUE && board[row - 2][col] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                else if(board[row - 1][col] == RED &&
                        board[row - 2][col] == RED){
                    mark_square_as(board, size, row, col, BLUE, announce);
                }
                
                else if (board[row + 1][col ] == BLUE &&
                         board[row + 2][col] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                else if(board[row + 1][col] == RED &&
                        board[row + 2][col] == RED){
                    mark_square_as(board, size, row, col, BLUE, announce);
                }
                
                
            }
            
            
        }
        
    }
    
    
}


void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    int numRed = 0;
    int numBlue = 0;
    for (int i = 0; i < size; i++){
        if (board[row][i] == RED){
            numRed++;
        }
        if (board[row][i] == BLUE){
            numBlue++;
        }
    }
    
    if (numRed == (size / 2)){
        for (int i = 0; i < size; i++){
            if (board[row][i] == UNKNOWN){
                mark_square_as(board, size, row, i, BLUE, announce);
            }
        }
    }
    if (numBlue == (size / 2)){
        for (int i = 0; i < size; i++){
            if (board[row][i] == UNKNOWN){
                mark_square_as(board, size, row, i, RED, announce);
            }
        }
    }
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    int numRed = 0;
    int numBlue = 0;
    for (int i = 0; i < size; i++){
        if (board[i][col] == RED){
            numRed++;
        }
        if (board[i][col] == BLUE){
            numBlue++;
        }
    }
    
    if (numRed == (size / 2)){
        for (int i = 0; i < size; i++){
            if (board[i][col] == UNKNOWN){
                mark_square_as(board, size, i, col, BLUE, announce);
            }
        }
    }
    if (numBlue == (size / 2)){
        for (int i = 0; i < size; i++){
            if (board[i][col] == UNKNOWN){
                mark_square_as(board, size, i, col, RED, announce);
            }
        }
    }
}


///////////////////////////////////////
// GAMEPLAY FUNCTIONS /////////////////
///////////////////////////////////////

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    bool noUnknown = true;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (board[i][j] == UNKNOWN){
                noUnknown = false;
            }
        }
    }
    if (noUnknown == true){
        if (board_has_no_duplicates(board, size) &&
            board_has_no_threes(board, size) && board_is_balanced(board, size)){
            return true;
        }
    }
    return false;
}

bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    // your code here
    return false;
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    // your code here
    return false;
}


///////////////////////////////////////
// S'MORE FUNCTIONS ///////////////////
///////////////////////////////////////


void solve_lookahead_row(int board[MAX_SIZE][MAX_SIZE],
                         int size,
                         int row,
                         bool announce) {
    // your code here
}

void solve_lookahead_column(int board[MAX_SIZE][MAX_SIZE],
                            int size,
                            int col,
                            bool announce) {
    // your code here
}
