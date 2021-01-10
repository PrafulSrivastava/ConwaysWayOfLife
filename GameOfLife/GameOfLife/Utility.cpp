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
	static HANDLE handle = NULL;
	if (!handle) {
		handle = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD point = { x ,y };
	SetConsoleCursorPosition(handle, point);
}