#include <iostream>
#include <bits/stdc++.h>
#include "sudoku.h"
using namespace std;

int main() {
	int difficulty{};
	do {
		cout << "Please Enter a number to choose your difficulty level:" << endl;
		cout << "1: Easy" << endl;
		cout << "2: Medium" << endl;
		cout << "3: Hard" << endl;
		cout << "4: Extreme" << endl;
		cin >> difficulty;
		} while (difficulty < 1 || difficulty > 4);
	sudoku s1;
	s1.fill_board(difficulty);
	s1.print_board();
	
}