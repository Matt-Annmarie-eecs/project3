/**
 * ohhi.cpp
 *
 * EECS 183
 * Project 3: 0h h1
 * Fall 2017
 *
 * Matthew Waldeck, Ann-Marie Zheng
 *
 * mwaldeck, annzheng
 *
 *
 * project three for eecs 183 which consists of a function implementations for 
 * a game of ohh1
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
    // minus 2 to prevent loop from going out of bounds
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
        if (!row_has_no_threes_of_color(board, size, i, RED) ||
            !row_has_no_threes_of_color(board, size, i, BLUE)){
            return false;
        }
        
        if (!col_has_no_threes_of_color(board, size, i, RED) ||
            !col_has_no_threes_of_color(board, size, i, BLUE)){
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
        if ((board[row1][col] == UNKNOWN) || (board[row2][col] == UNKNOWN)){
            return true;
        }
        
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
        if (board[row][col1] == UNKNOWN || board[row][col2] == UNKNOWN){
            return true;
        }
        
        if(board[row][col1] != board[row][col2]){
            return true;
        }
    }
    
    return false;
}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
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
        // impossible to solve for three in a row when there are only two spaces 
        if(size == 2){
            break;
        }
        // add/subrtact 1 or 2 to check square relative to selected square
        else if(board[row][col] == UNKNOWN){
            
            if (col == 0){
                
                if (board[row][col + 1] == BLUE && board[row][col + 2] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                
                else if(board[row][col + 1] == RED &&
                        board[row][col + 2] == RED){
                    mark_square_as(board, size, row, col, BLUE, announce);
                }
            }
            /* condition for col == size - 1 to prevent loop from going out of
             * bounds
             */
            else if (col == size - 1){
                
                if (board[row][col - 1] == BLUE && board[row][col - 2] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                
                else if(board[row][col - 1] == RED &&
                         board[row][col - 2] == RED){
                    mark_square_as(board, size, row, col, BLUE, announce);
                }

            }
            // condition for col == 1 to prevent loop from going out of bounds
            else if (col == 1){
                
                if (board[row][col + 1] == BLUE &&
                    board[row][col - 1] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                
                else if (board[row][col + 1] == RED &&
                         board[row][col - 1] == RED){
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
            /* condition for col == size - 2 to prevent loop from going out of
             * bounds
             */
            else if (col == size - 2){
                
                if (board[row][col + 1] == BLUE &&
                    board[row][col - 1] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                
                else if (board[row][col + 1] == RED &&
                         board[row][col - 1] == RED){
                    mark_square_as(board, size, row, col, BLUE, announce);
                }
                
                else if (board[row][col - 1] == BLUE &&
                         board[row][col - 2] == BLUE){
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
                
                else if (board[row][col - 1] == BLUE &&
                         board[row][col - 2] == BLUE){
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
        // impossible to solve for three in a row when there are only two spaces
        if(size == 2){
            break;
        }
        // add/subrtact 1 or 2 to check square relative to selected square
        else if(board[row][col] == UNKNOWN){
            
            if (row == 0){
                
                if (board[row + 1][col] == BLUE && board[row + 2][col] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                
                else if(board[row + 1][col] == RED &&
                        board[row + 2][col] == RED){
                    mark_square_as(board, size, row, col, BLUE, announce);
                }
            }
            /* condition for row == size - 1 to prevent loop from going out of
             * bounds
             */
            else if (row == size - 1){
                
                if (board[row - 1][col] == BLUE && board[row - 2][col] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                
                else if(board[row - 1][col] == RED &&
                        board[row - 2][col] == RED){
                    mark_square_as(board, size, row, col, BLUE, announce);
                }
                
            }
            // condition for row == 1 to prevent loop from going out of bounds
            else if (row == 1){
                
                if (board[row + 1][col] == BLUE &&
                    board[row - 1] [col] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                
                else if (board[row + 1][col] == RED &&
                         board[row - 1][col] == RED){
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
            /* condition for row == size - 2 to prevent loop from going out of
             * bounds
             */
            else if (row == size - 2){
                
                if (board[row + 1][col] == BLUE &&
                    board[row - 1] [col] == BLUE){
                    mark_square_as(board, size, row, col, RED, announce);
                }
                
                else if (board[row + 1][col] == RED &&
                         board[row - 1][col] == RED){
                    mark_square_as(board, size, row, col, BLUE, announce);
                }
                
                else if (board[row - 1][col] == BLUE &&
                         board[row - 2][col] == BLUE){
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
                
                
                else if (board[row - 1][col] == BLUE &&
                         board[row - 2][col] == BLUE){
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
    // numRed and numBlue hold number of red/blue squares
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
    // divide by 2 to get half of board size
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
    // numRed and numBlue hold number of red/blue squares
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
    // divide by 2 to get half of board size
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
    // use 0 to check if there are no unknown squares
    if (count_unknown_squares(board, size) == 0){
        
        if (board_is_valid(board, size)){
            return true;
        }
    }
    return false;
}

bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    /* validRow, validCol, validColor all hold bool for whether the row, column, 
     * or color is valid. will later be used to see if overall input is valid
     */
    bool validRow = false;
    /* 1 is the smallest valid input for row because display board is not zero
     * indexed
     */
    if ((row_input <= size) && (row_input >= 1)){
        validRow = true;
    }
    
    bool validCol = false;
    col_input = toupper(col_input);
    // subtract 1 from 'A' + size because 'A' is inclusive in size
    if ((col_input >= 'A') && (col_input <= ('A' + size - 1))){
        validCol = true;
    }
    
    bool validColor = false;
    color_char = toupper(color_char);
    if ((color_char == RED_LETTER) || (color_char == BLUE_LETTER) ||
        (color_char == UNKNOWN_LETTER)){
        validColor = true;
    }
    
    if (validRow && validCol && validColor){
        // subtract 1 to get zero indexed row number
        row = row_input - 1;
        // subtract 'A' to change ascii number to zer indexed row number
        col = col_input - 'A';
        return true;
    }
    
    cout << "Sorry, that's not a valid input." << endl;
    return false;
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    
    //hypothetical board that tests whether a move is valid
    int hypo_board[MAX_SIZE][MAX_SIZE];
    copy_board(current_board, hypo_board, size);
    
    /*overarching conditional structure checks whether
     *the selected point was an original point
     *
     *nested conditional structure tests whether
     *the move is valid
     */
    if (original_board[row][col] == UNKNOWN){
        mark_square_as(hypo_board, size, row, col, color, false);
        
        if(board_is_valid(hypo_board, size)){
            return true;
        }
        
        else {
            cout << "Sorry, that move violates a rule." << endl;
        }
            
    }

    else{
        cout << "Sorry, original squares cannot be changed." << endl;
    }
    
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
