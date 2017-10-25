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
 * code for project 3 of eecs183 which is a game of ohh1
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"


void test_count_unknown_squares();

void test_row_has_no_threes_of_color();

void test_col_has_no_threes_of_color();

void test_board_has_no_threes();

void test_solve_three_row();

void test_solve_balance_row();

void test_solve_three_row();

void test_solve_balance_row();

void test_solve_balance_column();

/*requires: nothing
 *modifies: cout
 *effects: prints various test cases to the console for function
 *board_has_no_duplicates
 */
void test_duplicates();

// declare more test functions here

int main() {
    test_solve_three_row();
    // add calls to test functions here

    return 0;
}


void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"O-OX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << count_unknown_squares(board, size_1) << endl;

    // add more tests here
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





