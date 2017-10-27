/**
 * test.cpp
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 * Fall 2017
 *
 * Matthew Waldeck
 * mwaldeck
 *
 * Ann-Marie Zheng
 * annzheng
 *
 * test cases for project 3 of eecs183 which is a game of ohh1
 */


#include <iostream>
#include "utility.h"
#include "ohhi.h"

/*requires: nothing
 *modifies: cout
 *effects: prints various test cases to the console for function
 *board_has_no_duplicates
 */

void test_count_unknown_squares();

void test_row_has_no_threes_of_color();

void test_col_has_no_threes_of_color();

void test_board_has_no_threes();

void test_solve_three_row();

void test_solve_balance_row();

void test_solve_three_row();

void test_solve_balance_row();

void test_solve_balance_column();

void test_solve_three_col();

void test_rows_are_different();

void test_check_valid_input();

void test_check_valid_move();


void test_duplicates();

<<<<<<< HEAD
=======


>>>>>>> 5dedcbe68f37cd2af877ee59fdf991c3314582b4
int main() {
     test_duplicates();
    
     test_count_unknown_squares();
    
     test_row_has_no_threes_of_color();
    
     test_col_has_no_threes_of_color();
    
     test_board_has_no_threes();
    
     test_solve_three_row();
    
     test_solve_balance_row();
    
     test_solve_three_row();
    
     test_solve_balance_row();
    
     test_solve_balance_column();
    
     test_solve_three_col();
    
     test_rows_are_different();
    
     test_check_valid_input();
    
     test_check_valid_move();
    
   

    return 0;
}


void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = {"O-OX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << count_unknown_squares(board, size_1) << endl;

<<<<<<< HEAD
=======
    
>>>>>>> 5dedcbe68f37cd2af877ee59fdf991c3314582b4
}

void test_row_has_no_threes_of_color(){
    int board[MAX_SIZE][MAX_SIZE];
    cout << "Testing row_has_no_threes_of_color()";
    
    string test_board_1[] = {"OOOX",
                             "XXXO",
                             "--XX",
                             "XXOX"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << row_has_no_threes_of_color(board, size_1, 0, BLUE) << endl;
    
    string test_board_2[] = {"OOOX",
                             "XXXO",
                             "--XX",
                             "XXOX"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << row_has_no_threes_of_color(board, size_2, 1, RED) << endl;
    
    string test_board_3[] = {"OOOX",
                             "XXXO",
                             "--XX",
                             "XXOX"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << row_has_no_threes_of_color(board, size_3, 2, RED) << endl;
    
    
}

void test_col_has_no_threes_of_color(){
    int board[MAX_SIZE][MAX_SIZE];
    
    string test_board_1[] = {"OOOX",
                             "OXXO",
                             "O-XX",
                             "XXOX"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << col_has_no_threes_of_color(board, size_1, 0, BLUE) << endl;
    
    string test_board_2[] = {"OXOX",
                             "OXXO",
                             "OXXX",
                             "XOOX"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << col_has_no_threes_of_color(board, size_2, 1, RED) << endl;
    
    string test_board_3[] = {"OXOX",
                             "XOXO",
                             "OXOX",
                             "XOOX"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << col_has_no_threes_of_color(board, size_3, 1, RED) << endl;
    
}

void test_board_has_no_threes(){
    int board[MAX_SIZE][MAX_SIZE];
    
    string test_board_1[] = {"OOOX",
                             "OXXO",
                             "O-XX",
                             "XXOX"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_threes(board, size_1) << endl;
    
    string test_board_2[] = {"OOXX",
                             "OXXO",
                             "O-XX",
                             "XXOX"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_has_no_threes(board, size_2) << endl;
    
    string test_board_3[] = {"XOOX",
                             "OXXO",
                             "O-XX",
                             "XXOX"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_has_no_threes(board, size_3) << endl;
    
    string test_board_5[] = {"XOOX",
                             "XXXO",
                             "O-XX",
                             "XXOX"};
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << board_has_no_threes(board, size_5) << endl;
    
    string test_board_6[] = {"XOOX",
                             "XXOO",
                             "X-XX",
                             "XXOX"};
    int size_6 = 4;
    read_board_from_string(board, test_board_6, size_6);
    cout << board_has_no_threes(board, size_6) << endl;
    
}

void test_duplicates(){
    int board[MAX_SIZE][MAX_SIZE];
    
    string test_board_1[] = {"OOOX",
                             "OXXO",
                             "O-XX",
                             "XXOX"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_duplicates(board, 4) << " : should be true" << endl;
    
    int board2[MAX_SIZE][MAX_SIZE];
    
    string test_board_2[] = {"OXXO",
                             "OXXO",
                             "O-XX",
                             "XXOX"};
    int size_2 = 4;
    read_board_from_string(board2, test_board_2, size_2);
    cout << board_has_no_duplicates(board2, 4) << " : should be false" << endl;
    
    
    int board3[MAX_SIZE][MAX_SIZE];
    string test_board_3[] = {"OOXO",
                             "OXOO",
                             "X-XX",
                             "XXOX"};
    int size_3 = 4;
    read_board_from_string(board3, test_board_3, size_3);
    cout << board_has_no_duplicates(board3, 4) << " : should be false" << endl;
    
    cout << endl;
}

void test_solve_three_row(){
    
    int board[MAX_SIZE][MAX_SIZE];
    
    string test_board[] = {"OOOX",
                           "OXXO",
                           "O-OX",
                           "XXOX"};
    int size = 4;
    read_board_from_string(board, test_board, size);
    cout << "initial board:" << endl;
    print_board(board, size);
    solve_three_in_a_row(board, size , 2, true);
    cout << endl;
    print_board(board, size);
    
    
    
    cout << endl;
    
    string test_board1[] = {"OOOX",
        "OXXO",
        "X-OX",
        "OXX-"};
    size = 4;
    read_board_from_string(board, test_board1, size);
    cout << "initial board:" << endl;
    print_board(board, size);
    solve_three_in_a_row(board, size , 3, true);
    cout << endl;
    print_board(board, size);
    
    
    
    cout << endl;
    
}

void test_solve_balance_row(){
    int board[MAX_SIZE][MAX_SIZE];
    
    string test_board_1[] = {"--OO",
                             "-XX-",
                             "O-XX",
                             "XXOX"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_balance_row(board, size_1, 0, true);
    print_board(board, size_1);
    cout << endl;

    string test_board_2[] = {"--OO",
                             "-XX-",
                             "O-XX",
                             "XXOX"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    solve_balance_row(board, size_2, 1, true);
    print_board(board, size_2);
    cout << endl;
    
    string test_board_3[] = {"--OO",
                             "-XX-",
                             "X-XX",
                             "XXOX"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    solve_balance_row(board, size_3, 2, true);
    print_board(board, size_3);
    cout << endl;
    
    string test_board_4[] = {"--OO",
                             "-XX-",
                             "X-XX",
                             "X-OX"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    solve_balance_row(board, size_4, 3, true);
    print_board(board, size_4);
    cout << endl;
}

void test_solve_balance_column(){
    int board[MAX_SIZE][MAX_SIZE];
    
    string test_board_1[] = {"--OO",
                             "-XX-",
                             "O-XX",
                             "OXOX"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_balance_column(board, size_1, 0, true);
    print_board(board, size_1);
     cout << endl;

    string test_board_2[] = {"--OO",
                             "-XX-",
                             "O-XX",
                             "OXOX"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    solve_balance_column(board, size_2, 1, true);
    print_board(board, size_2);
    cout << endl;
    
    string test_board_3[] = {"--OO",
                             "-XX-",
                             "O-XX",
                             "OXOX"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    solve_balance_column(board, size_3, 3, true);
    print_board(board, size_3);
    cout << endl;
    
    string test_board_4[] = {"--XO",
                             "-XX-",
                             "O-XX",
                             "OX-X"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    solve_balance_column(board, size_4, 2, true);
    print_board(board, size_4);
    cout << endl;

    
}


void test_solve_three_col(){
    
    
    int board[MAX_SIZE][MAX_SIZE];
    
    string test_board[] = {"---O",
        "-XX-",
        "O-XX",
        "OX-X"};
    int size = 4;
    read_board_from_string(board, test_board, size);
    print_board(board, size);
    solve_three_in_a_column(board, size, 2, true);
    print_board(board, size);
    
    
    cout << endl;
    
    
    
}

void test_rows_are_different(){
    
    int board[MAX_SIZE][MAX_SIZE];
    
    string test_board[] = {"----O-",
                           "X-OX--",
                           "--OO--",
                           "X----O",
                            "-O----",
                            "--X--X"};
    int size = 6;
    read_board_from_string(board, test_board, size);
    
    for(int row1 = 0; row1 < size; row1++){
        for(int row2 = 0; row2 < size; row2++){
            cout << "row " << row1 << " and row " << row2 << " are ";
            if(rows_are_different(board, size, row1, row2)){
                cout << "different" << endl;;
            }
            else if (!rows_are_different(board, size, row1, row2)){
                cout << "the same" << endl;;
            }
            
        }
    }
    
    
    cout << endl;
    
}

void test_check_valid_input(){
    int row = 0;
    int col = 0;
    
    check_valid_input(4, 2, 'a', 'x', row, col);
    cout << row << col << endl;
    
    check_valid_input(4, 4, 'd', '-', row, col);
    cout << row << col << endl;
    
    check_valid_input(8, 1, 'A', 'o', row, col);
    cout << row << col << endl;
    
    check_valid_input(4, 5, 'a', 'x', row, col);
    
    check_valid_input(4, 1, 'e', 'x', row, col);
    
    check_valid_input(4, 1, 'V', 'x', row, col);
    
    check_valid_input(4, 1, 'a', 'y', row, col);
    
    check_valid_input(4, 0, 'a', 'x', row, col);
    cout << row << col << endl;
    
    check_valid_input(2, 1, 'A', 'X', row, col);
    cout << row << col << endl;
    
    

    
    

}
void test_check_valid_move(){
    
    int board[MAX_SIZE][MAX_SIZE];
    int board2[MAX_SIZE][MAX_SIZE];
    string test_board[] = {"----O-",
        "X-OX--",
        "--OO--",
        "X----O",
        "-O----",
        "--X--X"};
    string test_board2[] = {"----O-",
        "X-OX-X",
        "--OO--",
        "X--X-O",
        "-O----",
        "O-X--X"};
    int size = 6;
    
    
    
    read_board_from_string(board, test_board, size);
     read_board_from_string(board2, test_board, size);
    cout << endl;
    if(check_valid_move(board, board2, size, 0, 1, BLUE)){
        cout << "0,1 is working" << endl;
    }
    
    if(check_valid_move(board, board2, size, 5, 0, BLUE)){
        cout << "5,0 is working" << endl;
    }
    
    if(!check_valid_move(board, board2, size, 4, 1, BLUE)){
        cout << "4,1 correctly rejected working" << endl;
    }
    if(!check_valid_move(board, board2, size, 1, 0, BLUE)){
        cout << "1,0 correctly rejected working" << endl;
    }
    if(!check_valid_move(board, board2, size, 2, 1, BLUE)){
        cout << "2,1 correctly rejected working" << endl;
    }
   
    
}




