#include "Utility.h"

HANDLE Utility::handle = NULL;

void Utility::ShowConsoleCursor(bool show)
{
	if (!handle)
		handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(handle, &cursorInfo);
	cursorInfo.bVisible = show;
	SetConsoleCursorInfo(handle, &cursorInfo);
}

void Utility::gotoxy(int x, int y) {
	if (!handle) {
		handle = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD point = { x , y };
	SetConsoleCursorPosition(handle, point);
}

string Utility::get_color() {
	int color = rand() % 8;
	switch (color) {
	case 0:
		return "Color 0A";
	case 1:
		return "Color 0B";
	case 2:
		return "Color 0C";
	case 3:
		return "Color 0D";
	case 4:
		return "Color 0E";
	case 5:
		return "Color 0F";
	case 6:
		return "Color 00";
	case 7:
		return "Color 09";
	}
}