#include <iostream>
#include "Grid.h"
#include "Cells.h"
#include <time.h>
#include <thread>
#include "Utility.h"
#include "Organisms.h"

using namespace std;

static  int *x = new int();
static  int *y = new int();


int main() {
	Utility::ShowConsoleCursor(false);
	srand(time(NULL));
	Grid::populate();
	//diagonal_mover();
	Organisms::diagonal_mover_left_top();
	Organisms::diagonal_mover_right_top();
	Organisms::diagonal_mover_left_bottom();
	Organisms::diagonal_mover_right_bottom();

	//triangle_dot();
	int turn = 0;
	while (true) {
		Cells::reset_bools();
		system(Utility::get_color().c_str());
		Utility::gotoxy(0, 0);
		Grid::display_grid();
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				*x = i;
				*y = j;
				Cells::life_decisions(*x, *y);
			}
		}		
		Cells::bring_back_marked_cells();
		Cells::kill_marked_cells();
		if (!Cells::has_changed()) {
			Organisms::call_diagonal_mover_randomly();
		}
		//this_thread::sleep_for(chrono::milliseconds(1));
		turn++;
	}
	delete x;
	delete y;
	x = NULL;
	y = NULL;

	return 1;
}