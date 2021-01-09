#include <iostream>
#include "Grid.h"
#include "Cells.h"
#include <time.h>
#include <thread>
using namespace std;

static  int *x = new int();
static  int *y = new int();
int main() {
	srand(time(NULL));
	Grid::populate();
	Grid::grid[4][2] = 1;
	Grid::grid[5][3] = 1;
	Grid::grid[4][1] = 1;
	Grid::grid[3][2] = 1;
	while (true) {
		Grid::gotoxy(0, 0);
		Grid::display_grid();
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				*x = i;
				*y = j;
				Cells::life_decisions(*x, *y);
				//this_thread::sleep_for(chrono::milliseconds(100));
			}
		}
		
		Cells::bring_back_marked_cells();
		Cells::kill_marked_cells();
		this_thread::sleep_for(chrono::milliseconds(1000));

		Grid::gotoxy(0, 0);
		Grid::clear_grid();
	}
	delete x;
	delete y;
	x = NULL;
	y = NULL;

	return 1;
}