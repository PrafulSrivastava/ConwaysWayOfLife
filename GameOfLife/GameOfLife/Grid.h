#pragma once
#include <iostream>
#include <vector>
#include <windows.h>

#define HEIGHT 15
#define WIDTH 15

using namespace std;

class Grid {
	
public:
	static vector<vector<int>> grid;
	static void populate();
	static void display_grid();
	
	static void randomise();
	static void clear_grid();
};