#include "Cells.h"

using namespace std;

bool Cells::are_killed = false;
bool Cells::are_born = false;

void Cells::reset_bools() {
	are_killed = false;
	are_born = false;
}

int Cells::count_alive_cells() {
	int alive_cnt = 0;
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (Grid::grid[i][j] == CELL_STATE_ALIVE)
				alive_cnt++;
		}
	}
	return alive_cnt;
}

int Cells::count_of_neighbors(const int &row, const int &col) {
	int neighbours = 0;
	for (int i = row - 1; (i < (row + 2) && i < HEIGHT); i++) {
		for (int j = col - 1; (j < (col + 2) && (j < WIDTH)); j++) {
			if (i < 0 || i == HEIGHT)
				continue;
			if (j < 0 || j == WIDTH)
				continue;
			if (i == row && j == col) { 
				continue;
			}
			if (Grid::grid[i][j] == CELL_STATE_ALIVE || Grid::grid[i][j] == CELL_STATE_MARK_DEAD)
				neighbours++;
		}
	}
	return neighbours;
}

void Cells::mark_for_bringing_back_to_life(const int &row, const int &col) {
	Grid::grid[row][col] = CELL_STATE_MARK_ALIVE;
	are_born = true;
}

void Cells::kill_cell(const int &row, const int &col) {
	Grid::grid[row][col] = CELL_STATE_MARK_DEAD;
	are_killed = true;
}

void Cells::life_decisions(unsigned int row, unsigned int col) {
	int neighbours = count_of_neighbors(row, col);
	switch (neighbours) {
	case 0:
	case 1:
		/* Lonliness */
		if(Grid::grid[row][col] == CELL_STATE_ALIVE)
			kill_cell(row, col);
		break;
	case 2: /*just stay alive*/
		break;
	case 3:
		if (Grid::grid[row][col] == CELL_STATE_DEAD) {
			mark_for_bringing_back_to_life(row, col);
		}
			
		break;
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
		/* Overpopulation */
		if (Grid::grid[row][col] == CELL_STATE_ALIVE)
			kill_cell(row, col);
		break;

	}
}

void Cells::bring_back_marked_cells() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (Grid::grid[i][j] == CELL_STATE_MARK_ALIVE)
				Grid::grid[i][j] = CELL_STATE_ALIVE;
		}
	}
}

void Cells::kill_marked_cells() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (Grid::grid[i][j] == CELL_STATE_MARK_DEAD)
				Grid::grid[i][j] = CELL_STATE_DEAD;
		}
	}
}

bool Cells::has_changed() {
	return (are_killed || are_born);
}