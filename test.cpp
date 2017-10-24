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


// declare more test functions here

int main() {
    test_count_unknown_squares();
    
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
    
        
}

