﻿#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <Windows.h>
#include "TitleScene.h"
#include "console.h"

void TitleRender()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"███▄ ▄███▓ ██▓  ██████ ▄▄▄█████▓▓█████  ██▀███ ▓██   ██▓    ██▒   █▓ ██▓ ██▓     ██▓    ▄▄▄        ▄████ ▓█████" << endl;  
	wcout << L"▓██▒▀█▀ ██▒▓██▒▒██    ▒ ▓  ██▒ ▓▒▓█   ▀ ▓██ ▒ ██▒▒██  ██▒   ▓██░   █▒▓██▒▓██▒    ▓██▒   ▒████▄     ██▒ ▀█▒▓█   ▀" << endl;
	wcout << L"▓██    ▓██░▒██▒░ ▓██▄   ▒ ▓██░ ▒░▒███   ▓██ ░▄█ ▒ ▒██ ██░    ▓██  █▒░▒██▒▒██░    ▒██░   ▒██  ▀█▄  ▒██░▄▄▄░▒███" << endl;
	wcout << L"▒██    ▒██ ░██░  ▒   ██▒░ ▓██▓ ░ ▒▓█  ▄ ▒██▀▀█▄   ░ ▐██▓░     ▒██ █░░░██░▒██░    ▒██░   ░██▄▄▄▄██ ░▓█  ██▓▒▓█  ▄"<< endl;
	wcout << L"▒██▒   ░██▒░██░▒██████▒▒  ▒██▒ ░ ░▒████▒░██▓ ▒██▒ ░ ██▒▓░      ▒▀█░  ░██░░██████▒░██████▒▓█   ▓██▒░▒▓███▀▒░▒████▒" << endl;
	wcout << L"░ ▒░   ░  ░░▓  ▒ ▒▓▒ ▒ ░  ▒ ░░   ░░ ▒░ ░░ ▒▓ ░▒▓░  ██▒▒▒       ░ ▐░  ░▓  ░ ▒░▓  ░░ ▒░▓  ░▒▒   ▓▒█░ ░▒   ▒ ░░ ▒░ ░" << endl;
	wcout << L"		░  ░      ░ ▒ ░░ ░▒  ░ ░    ░     ░ ░  ░  ░▒ ░ ▒░▓██ ░▒░       ░ ░░   ▒ ░░ ░ ▒  ░░ ░ ▒  ░ ▒   ▒▒ ░  ░   ░  ░ ░  ░" << endl;
	wcout << L"░      ░    ▒ ░░  ░  ░    ░         ░     ░░   ░ ▒ ▒ ░░          ░░   ▒ ░  ░ ░     ░ ░    ░   ▒   ░ ░   ░    ░" << endl;
	int curmode = _setmode(_fileno(stdout), prevmode);
}

void StoryRender()
{
	system("cls");
	cout << "프롤로그" << endl;
	cout << endl;
	cout << "경찰인 주인공은 최근 살인사건이 발생하였다는 신고를 받고 어느 작은 마을로 이동하게 된다." << endl;			 
	cout << "도착하고 주인공은 마을 주민들과 이야기하다가 살인사건이 발생한 건물 조사를 위해 그 건물 들어가게된다." << endl;
	cout << "하지만 그곳에서 온갖 비자연적인 현상이 일어나는데..." << endl;
	cout << "주인공은 과연 사건을 해결하고 살아남을 수 있을 것 인가?" << endl;
	Sleep(200);
	while (1)
	{
		if (KeyController() == KEY::SPACE)
		{
			break;
		}
	}
}

MENU MenuRender()
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 6;
	int y = Resolution.Y / 2.5;
	int originy = y;
	Gotoxy(x, y);
	cout << "처음부터" << endl;
	Gotoxy(x, y + 1);
	cout << "스토리보기" << endl;
	Gotoxy(x, y + 2);
	cout << "게임종료" << endl;
	while (1)
	{
		KEY eKey = KeyController();
		switch (eKey)
		{
		case KEY::UP:
		{
			if (y > originy)
			{
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, --y);
				cout << ">";
				Sleep(200);
			}
		}
		break;
		case KEY::DOWN:
		{
			if (y < originy + 2)
			{
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, ++y);
				cout << ">";
				Sleep(200);
			}
		}
		break;	
		case KEY::SPACE:
		{
			if (originy == y)
			{
				return MENU::START;
			}
			else if (originy + 1 == y)
				return MENU::STORY;
			else if (originy + 2 == y)
				return MENU::QUIT;
		}
		break;
		}
	}
	return MENU::STORY;
}

KEY KeyController()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		return KEY::UP;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		return KEY::DOWN;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		return KEY::SPACE;

	return KEY::NONE;
}

void EnterAnimation()
{
	COORD Resolution = GetConsoleResolution();
	int width = Resolution.X / 2;
	int height = Resolution.Y;
	int animatime = 20;
	for (int i = 0; i < 5; i++)
	{
		SetColor((int)COLOR::WHITE, (int)COLOR::WHITE);
		system("cls");
		Sleep(animatime);
		SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
		system("cls");
		Sleep(animatime);
	}
}

bool TitleScene()
{
	while (1)
	{
		TitleRender();
		MENU eMenu = MenuRender();
		switch (eMenu)
		{
		case MENU::START:
			EnterAnimation();
			break;
		case MENU::STORY:
			StoryRender();
			break;
		case MENU::QUIT:
			return false;
		}
	}
}