#include <iostream>
#include <bits/stdc++.h>
#include "sudoku.h"

using namespace std;

int main() {
	sudoku s1;
	s1.fill_diag_boxes();
	s1.print_board();
}