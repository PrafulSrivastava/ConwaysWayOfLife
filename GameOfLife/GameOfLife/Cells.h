#pragma once
#include <iostream>
#include "Grid.h"

using namespace std;

#define CELL_STATE_ALIVE 1
#define CELL_STATE_DEAD 0
#define CELL_STATE_MARK_ALIVE -1
#define CELL_STATE_MARK_DEAD -2

class Cells {

public:

	static int count_of_neighbors(const int &row, const int &col);
	static void mark_for_bringing_back_to_life(const int& row, const int& col);
	static void kill_cell(const int& row, const int& col);
	static void life_decisions(unsigned int row, unsigned int col);
	static void bring_back_marked_cells();
	static void kill_marked_cells();
};