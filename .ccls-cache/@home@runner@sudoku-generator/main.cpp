#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void fill_diag_boxes(int[][9]);
bool fill_remainder(int[][9], int, int);
void fill_square(int[][9], int, int);
bool h_valid(int[][9], int, int, int);
bool v_valid(int[][9], int, int, int);
bool s_valid(int[][9], int, int, int);
bool is_valid(int[][9], int, int, int);
void print_board(int[][9]);

int main() {
  int board[9][9] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	fill_diag_boxes(board);
	print_board(board);
	fill_remainder(board, 0, 3);

	cout << endl;
	print_board(board);
	
}

// fill the top-left, middle, and bottom-right boxes randomly.  The rest of the board will be filled out around these 3.
void fill_diag_boxes(int board[][9]) {
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

bool fill_remainder(int board[][9], int row, int col) {
	
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
			if (row >= 9) {
				return true;
			}
		}
	}
	for (int i = 1; i < 10; i++) {
		if (is_valid(board, row, col, i)) {
			board[row][col] = i;
			// print_board(board);
			if (fill_remainder(board, row, col+1)) {
				return true;
			} else {
				board[row][col] = 0;
			}
		}
	}
	return false;
	
}



bool h_valid(int board[][9], int row, int col, int val) {
	for (int i = 0; i < 9; i++) {
		if (board[row][i] == val) {
			return false;
		}
	}
	return true;
}

bool v_valid(int board[][9], int row, int col, int val) {
	for (int i = 0; i < 9; i++) {
		if (board[i][col] == val) {
			return false;
		}
	}
	return true;
}

bool s_valid(int board[][9], int row, int col, int val) {
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

bool is_valid(int board[][9], int row, int col, int val) {
	return (s_valid(board, row, col, val) && h_valid(board, row, col, val) && v_valid(board, row, col, val));
}

void print_board(int board[][9]) {
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