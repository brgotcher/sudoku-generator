#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void fill_diag_boxes(int[][9]);
void fill_remainder(int[][9]);
void fill_square(int[][9], int, int);
bool h_valid(int[][9], int, int, int);
bool v_valid(int[][9], int, int, int);
bool s_valid(int[][9], int, int, int);
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
	fill_remainder(board);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	
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

void fill_remainder(int board[][9]) {
	
	for (int r = 0; r < 9; r+= 3) {
		for (int c = 0; c < 9; c+=3) {
			if (board[r][c] == 0) {
				fill_square(board, r, c);
				print_board(board);
			}
		}
	}
	
}

void fill_square(int board[][9], int row, int col) {
	for (int r = row; r < row+3; r++) {
		for (int c = col; c < col+3; c++) {
			int val = rand() % 9 + 1;
			while (!h_valid(board, r, c, val) || !v_valid(board, r, c, val) || !s_valid(board, r, c, val)) {
				val = rand() % 9 + 1;
			}
			board[r][c] = val;
		}
	}
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
			if (board[r][c] == val) {
				return false;
			}
		}
	}
	return true;
}

void print_board(int board[][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}