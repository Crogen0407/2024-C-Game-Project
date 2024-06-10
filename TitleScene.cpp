#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <Windows.h>
#include "TitleScene.h"

void TitleRender()
{
}

void InfoRender()
{
	Sleep(100);
	while (true)
	{
		if (KeyController() == KEY::SPACE)
		{
			system("cls");
			break;
		}
	}
}

MENU MenuRender()
{
	return MENU();
}

KEY KeyController()
{
	return KEY();
}

void EnterAnimation()
{
}
