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
 * code for project 3 of eecs183 which is a game of ohh1
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"


void test_count_unknown_squares();

void test_row_has_no_threes_of_color();

void test_col_has_no_threes_of_color();

void test_board_has_no_threes();

// declare more test functions here

int main() {
    test_row_has_no_threes_of_color();
    
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
