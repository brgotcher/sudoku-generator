#include <iostream>
#include <bits/stdc++.h>
#include "sudoku.h"

using namespace std;

sudoku::sudoku() : board{
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0}
	}
	{}

void sudoku::fill_board(const int blanks) {
	fill_diag_boxes();
	fill_remainder(0,3);
	delete_squares(blanks);
}
// randomly fill the top left, middle, and bottom right squares of 9 cells
void sudoku::fill_diag_boxes() {
	// create a vector of the numbers to be used
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	// the vector will be shuffled & used 3 times to fill out 3 boxes
	// outermost loop (l) traverses the 3 boxes
	for (int l = 0; l < 3; l++) {
		srand(time(NULL));
		random_shuffle(nums.begin(), nums.end());
		int x = 0;
		// mid loop (i) traverses the 3 rows of the current box
		for (int i = (l*3); i < ((l*3)+3); i++) {
			// inner loop (j) traverses the 3 elements within the current row
			for (int j = (l*3); j < ((l*3)+3); j++) {
				board[i][j] = nums[x++];
			}
		}
	}
}

// fill out the rest of the board based on the randomized squares
bool sudoku::fill_remainder(int row, int col) {
	
	// when end of row is reached, move to next row
	if (col >= 9 && row < 9) {
		col = 0;
		row++;
	}

	// if the end of the grid has been reached, return true
	if (col >= 9 && row >= 9) {
		return true;
	}

	// if the current cel value is not zero, move to next box
	if (board[row][col] != 0) {
		col += 3;
		if (col >= 9) {
			col = 0; 
			row++;
			// return true if this was the last row
			if (row >= 9) {
				return true;
			}
		}
	}
	// check if there is a valid number that can fit the current cel. 
	// if so, place it and call the function on the next cel.  If not, return false.
	for (int i = 1; i < 10; i++) {
		if (is_valid(row, col, i)) {
			board[row][col] = i;
			// print_board(board);
			if (fill_remainder(row, col+1)) {
				return true;
			} else {
				board[row][col] = 0;
			}
		}
	}
	return false;
}

void sudoku::delete_squares(const int blanks) {
	srand(time(NULL));
	int row{}, col{};
	for (int i = 0; i < blanks; i++) {
		do {
			row = (rand() % 10);
			col = (rand() % 10);
			} while (board[row][col] == 0);
		board[row][col] = 0;
		
	}
}

// check if a value is valid for the current row
bool sudoku::h_valid(int row, int col, int val) const {
	for (int i = 0; i < 9; i++) {
		if (board[row][i] == val) {
			return false;
		}
	}
	return true;
}

// check if a value is valid for the current column
bool sudoku::v_valid(int row, int col, int val) const {
	for (int i = 0; i < 9; i++) {
		if (board[i][col] == val) {
			return false;
		}
	}
	return true;
}

// check if a value is valid for the current square
bool sudoku::s_valid(int row, int col, int val) const {
	// get the indices of the top left cel in the current square
	int top = row - (row % 3);
	int left = col - (col % 3);
	for (int r = top; r < (top+3); r++) {
		for (int c = left; c < left+3; c++) {
			if (board[r][c] == val && !(r == row && c == col)) {
				return false;
			}
		}
	}
	return true;
}

// combine the previous 3 functions to verify the value is valid in the current cel
bool sudoku::is_valid(int row, int col, int val) const {
	return (s_valid(row, col, val) && h_valid(row, col, val) && v_valid(row, col, val));
}


void sudoku::print_board() const {
	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0) {
			cout << " ------------------------" << endl;
		}
		for (int j = 0; j < 9; j++) {
			if (j % 3 == 0) {
				cout << "| ";
			}
			cout << board[i][j];
			if (j < 8) {
				cout << " ";
			} else {
				cout << " |";
			}
		}
		if ( i % 3 == 0) {
		}
		cout << endl;
	}
	cout << " ------------------------" << endl;
}