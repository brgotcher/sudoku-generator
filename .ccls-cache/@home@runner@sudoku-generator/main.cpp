#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void fill_diag_boxes(int[][9]);

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

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	
}

void fill_diag_boxes(int board[][9]) {
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (int l = 0; l < 3; l++) {
		srand(time(NULL));
		random_shuffle(nums.begin(), nums.end());
		int x = 0;
		for (int i = (l*3); i < ((l*3)+3); i++) {
			for (int j = (l*3); j < ((l*3)+3); j++) {
				board[i][j] = nums[x++];
			}
		}
	}

}