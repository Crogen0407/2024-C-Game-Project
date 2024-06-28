#include<Windows.h>
#include "console.h"

void FullScreen()
{
	//SetConsoleDisplayMode
	//(GetStdHandle(STD_OUTPUT_HANDLE),
	//	CONSOLE_FULLSCREEN_MODE, 0);
	ShowWindow(GetConsoleWindow(),
		SW_MAXIMIZE);
}

void Gotoxy(int _x, int _y)
{
	// 커서관련 구조체
	COORD Cur = { _x * 2, _y }; // {_x*2,_y}가 더 자연스러울 수 있음.
	// 커서포지션세팅하는 함수.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE)
		, Cur);
}

BOOL Gotoxytest(int _x, int _y)
{
	//COORD Cur = { _x, _y };
	COORD Cur = { _x * 2, _y };
	// 콘솔 커서 위치를 딱 세팅
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE)
		, Cur);
}
COORD CursorPos()
{
	CONSOLE_SCREEN_BUFFER_INFO Buf;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &Buf);
	return Buf.dwCursorPosition;
}

void SetCursorVis(bool _vis, DWORD _size)
{
	CONSOLE_CURSOR_INFO curinfo;
	curinfo.dwSize = _size;  // 커서 굵기(1~100)
	curinfo.bVisible = _vis; // True: On, False: Off
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &curinfo);
}

void SetColor(int _textcolor, int _bgcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE)
		, (_bgcolor << 4) | _textcolor);
}

int GetColor()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &info);
	int color = info.wAttributes & 0xf;
	return color;
}

void LockResize()
{
	HWND console = GetConsoleWindow();
	//NULL;
	// modern c++ 
	if (console != nullptr)
	{
		LONG style = GetWindowLong(console, GWL_STYLE);
		style &= ~WS_MAXIMIZEBOX & ~WS_SIZEBOX;// &~WS_HSCROLL;// &~WS_CAPTION;
		SetWindowLong(console, GWL_STYLE, style);
	}
}

COORD GetConsoleResolution()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &info);
	short width = info.srWindow.Right - info.srWindow.Left + 1;
	short height = info.srWindow.Bottom - info.srWindow.Top + 1;
	return COORD{ width, height };
}