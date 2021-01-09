#include "Grid.h"

vector<vector<int>> Grid::grid = { };

void Grid::gotoxy(int x, int y) {
	static HANDLE handle = NULL;
	if (!handle) {
		handle = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD point = { x ,y };
	SetConsoleCursorPosition(handle, point);

}

void Grid::display_grid() {

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (!grid[i][j])
				cout << "." << " ";
			else
				cout << "*" << " ";
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
			cout << "." << " ";
		}
		cout << endl;
	}
}