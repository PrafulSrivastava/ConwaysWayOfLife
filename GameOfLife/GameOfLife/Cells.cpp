#include "Cells.h"

using namespace std;

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
			if (Grid::grid[i][j] == CELL_STATE_ALIVE || Grid::grid[i][j] == CELL_STATE_MARK_TO_DEAD)
				neighbours++;
		}
	}
	return neighbours;
}

void Cells::mark_for_bring_back_to_life(const int &row, const int &col) {
	Grid::grid[row][col] = CELL_STATE_MARK_TO_LIVE;
}

void Cells::kill_cell(const int &row, const int &col) {
	Grid::grid[row][col] = CELL_STATE_MARK_TO_DEAD;
}

void Cells::life_decisions(unsigned int row, unsigned int col) {
	int neighbours = count_of_neighbors(row, col);
	//Grid::gotoxy(10, 10);
	//cout << "Cell {" << row << ", " << col << "} has " << neighbours << " neighbours!";
	//Grid::gotoxy(10, 11);
	
	switch (neighbours) {
	case 0:
	case 1:
		/* Lonliness */
		//cout << "Cell {" << row << ", " << col << "} died of lonliness";
		if(Grid::grid[row][col] == CELL_STATE_ALIVE)
			kill_cell(row, col);
		break;
	case 2: /*just stay alive*/
		break;
	case 3:
		if (Grid::grid[row][col] == CELL_STATE_DEAD) {
			//cout << "Cell {" << row << ", " << col << "} was brought back to life";
			mark_for_bring_back_to_life(row, col);
		}
			
		break;
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
		/* Overpopulation */
		//cout << "Cell {" << row << ", " << col << "} died of overpopulation";
		if (Grid::grid[row][col] == CELL_STATE_ALIVE)
			kill_cell(row, col);
		break;

	}
}

void Cells::bring_back_marked_cells() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (Grid::grid[i][j] == CELL_STATE_MARK_TO_LIVE)
				Grid::grid[i][j] = CELL_STATE_ALIVE;
		}
	}
}

void Cells::kill_marked_cells() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (Grid::grid[i][j] == CELL_STATE_MARK_TO_DEAD)
				Grid::grid[i][j] = CELL_STATE_DEAD;
		}
	}
}