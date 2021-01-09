#include <iostream>
#include "Grid.h"
#include "Cells.h"
#include <time.h>
#include <thread>
using namespace std;

static  int *x = new int();
static  int *y = new int();

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void triangle_dot() {
	Grid::grid[8][2] = 1;
	Grid::grid[9][3] = 1;
	Grid::grid[8][1] = 1;
	Grid::grid[7][2] = 1;
}
void diagonal_mover() {
	Grid::grid[0][1] = 1;
	Grid::grid[1][2] = 1;
	Grid::grid[2][2] = 1;
	Grid::grid[2][1] = 1;
	Grid::grid[2][0] = 1;
}

int main() {
	ShowConsoleCursor(false);
	srand(time(NULL));
	Grid::populate();
	diagonal_mover();
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
		this_thread::sleep_for(chrono::milliseconds(200));

		Grid::gotoxy(0, 0);
		Grid::clear_grid();
	}
	delete x;
	delete y;
	x = NULL;
	y = NULL;

	return 1;
}