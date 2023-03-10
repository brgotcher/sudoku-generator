#pragma once

class sudoku {
	public:
		sudoku();
		void print_board();
		void fill_board();
	private:
		int board[9][9];
		bool fill_remainder(int, int);
		void fill_diag_boxes();
		void fill_square(int, int);
		bool h_valid(int, int, int);
		bool v_valid(int, int, int);
		bool s_valid(int, int, int);
		bool is_valid(int, int, int);
};