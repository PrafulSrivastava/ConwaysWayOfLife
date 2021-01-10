#include "Organisms.h"

//void triangle_dot() {
//	Grid::grid[8][5] = 1;
//	Grid::grid[9][6] = 1;
//	Grid::grid[8][4] = 1;
//	Grid::grid[7][5] = 1;
//}
//void Organisms::diagonal_mover() {
//	Grid::grid[0][4] = 1;
//	Grid::grid[1][5] = 1;
//	Grid::grid[2][5] = 1;
//	Grid::grid[2][4] = 1;
//	Grid::grid[2][3] = 1;
//}

void Organisms::diagonal_mover_left_top() {
	Grid::grid[0][1] = 1;
	Grid::grid[1][2] = 1;
	Grid::grid[2][0] = 1;
	Grid::grid[2][1] = 1;
	Grid::grid[2][2] = 1;
}
void Organisms::diagonal_mover_right_top() {
	Grid::grid[0][WIDTH - 2] = 1;
	Grid::grid[1][WIDTH - 3] = 1;
	Grid::grid[2][WIDTH - 3] = 1;
	Grid::grid[2][WIDTH - 2] = 1;
	Grid::grid[2][WIDTH - 1] = 1;
}
void Organisms::diagonal_mover_right_bottom() {
	Grid::grid[WIDTH - 1][WIDTH - 2] = 1;
	Grid::grid[WIDTH - 2][WIDTH - 3] = 1;
	Grid::grid[WIDTH - 3][WIDTH - 3] = 1;
	Grid::grid[WIDTH - 3][WIDTH - 2] = 1;
	Grid::grid[WIDTH - 3][WIDTH - 1] = 1;
}

void Organisms::diagonal_mover_left_bottom() {
	Grid::grid[WIDTH - 1][1] = 1;
	Grid::grid[WIDTH - 2][2] = 1;
	Grid::grid[WIDTH - 3][0] = 1;
	Grid::grid[WIDTH - 3][1] = 1;
	Grid::grid[WIDTH - 3][2] = 1;
}
void Organisms::triangle_dot() {
	Grid::grid[8][9] = 1;
	Grid::grid[9][10] = 1;
	Grid::grid[8][8] = 1;
	Grid::grid[7][9] = 1;
}
void Organisms::diagonal_mover() {
	Grid::grid[0][4] = 1;
	Grid::grid[1][5] = 1;
	Grid::grid[2][5] = 1;
	Grid::grid[2][4] = 1;
	Grid::grid[2][3] = 1;
}
void Organisms::diagonal_mover_reverse() {
	Grid::grid[0][15] = 1;
	Grid::grid[1][14] = 1;
	Grid::grid[2][16] = 1;
	Grid::grid[2][15] = 1;
	Grid::grid[2][14] = 1;
}

void Organisms::third() {
	Grid::grid[3][4] = 1;
	Grid::grid[4][5] = 1;
	Grid::grid[5][6] = 1;
	Grid::grid[3][3] = 1;
	Grid::grid[4][3] = 1;
}
void Organisms::call_diagonal_mover_randomly() {
	int choice = rand() % 4;
	switch (choice) {
	case 0:
		diagonal_mover_left_top();
		break;
	case 1:

		diagonal_mover_right_top();
		break;
	case 2:
		diagonal_mover_left_bottom();
		break;
	case 3:
		diagonal_mover_right_bottom();
		break;
	}
}