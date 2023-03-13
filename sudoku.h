#pragma once

class sudoku {
	public:
		sudoku();
		void print_board() const;
		void fill_board(const int);
	private:
		int board[9][9];
		bool fill_remainder(int, int);
		void fill_diag_boxes();
		void fill_square(int, int);
		void delete_squares(const int);
		bool h_valid(int, int, int) const;
		bool v_valid(int, int, int) const;
		bool s_valid(int, int, int) const;
		bool is_valid(int, int, int) const;
};