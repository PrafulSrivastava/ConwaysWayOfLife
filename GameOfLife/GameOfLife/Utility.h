#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

class Utility {
	static HANDLE handle;
public:
	static void gotoxy(int x, int y);
	static void ShowConsoleCursor(bool showFlag);
};