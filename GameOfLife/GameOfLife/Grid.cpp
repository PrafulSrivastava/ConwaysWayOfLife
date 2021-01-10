#include "Grid.h"

vector<vector<int>> Grid::grid = { };

void Grid::display_grid() {

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (!grid[i][j])
				cout << DEAD_ORGANISM << " ";
			else
				cout << ALIVE_ORGANISM << " ";
		}
		cout << endl;
	}

}

void Grid::populate() {
	for (int i = 0; i < HEIGHT; i++) {
		vector<int> temp;
		for (int j = 0; j < WIDTH; j++) {
			temp.push_back(0);
		}
		grid.push_back(temp);
	}
}

void Grid::randomise() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			int t = rand() % 2;
			grid[i][j] = t;
		}
	}
}

void Grid::clear_grid() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			cout << DEAD_ORGANISM << " ";
		}
		cout << endl;
	}
}