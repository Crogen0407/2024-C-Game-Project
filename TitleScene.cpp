#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <Windows.h>
#include "TitleScene.h"
#include "console.h"

void TitleRender()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"IIIIIIIIII                                        iiii              d::::::d                                               tttt" << endl;  
	wcout << L"I::::::::I                                       i::::i             d::::::d                                            ttt:::t" << endl;
	wcout << L"I::::::::I                                        iiii              d::::::d                                            t:::::t" << endl;
	wcout << L"II::::::II                                                        d:::::d                                             t:::::t" << endl;
	wcout << L"  I::::Innnn  nnnnnnnn         cccccccccccccccc iiiiiii      ddddddddd:::::d     eeeeeeeeeeee    nnnn  nnnnnnnn    ttttttt:::::ttttttt" << endl;
	wcout << L"  I::::In:::nn::::::::nn     cc:::::::::::::::c i:::::i    dd::::::::::::::d   ee::::::::::::ee  n:::nn::::::::nn  t:::::::::::::::::t" << endl;
	wcout << L"  I::::In::::::::::::::nn   c:::::::::::::::::c  i::::i   d::::::::::::::::d  e::::::eeeee:::::een::::::::::::::nn t:::::::::::::::::t" << endl;
	wcout << L"  I::::Inn:::::::::::::::n c:::::::cccccc:::::c  i::::i  d:::::::ddddd:::::d e::::::e     e:::::enn:::::::::::::::ntttttt:::::::tttttt" << endl;
	wcout << L"  I::::I  n:::::nnnn:::::n c::::::c     ccccccc  i::::i  d::::::d    d:::::d e:::::::eeeee::::::e  n:::::nnnn:::::n      t:::::t" << endl;
	wcout << L"  I::::I  n::::n    n::::n c:::::c               i::::i  d:::::d     d:::::d e:::::::::::::::::e   n::::n    n::::n      t:::::t" << endl;
	wcout << L"  I::::I  n::::n    n::::n c:::::c               i::::i  d:::::d     d:::::d e::::::eeeeeeeeeee    n::::n    n::::n      t:::::t" << endl;
	wcout << L"  I::::I  n::::n    n::::n c::::::c     ccccccc  i::::i  d:::::d     d:::::d e:::::::e             n::::n    n::::n      t:::::t    tttttt" << endl;
	wcout << L"II::::::IIn::::n    n::::n c:::::::cccccc:::::c i::::::i d::::::ddddd::::::dde::::::::e            n::::n    n::::n      t::::::tttt:::::t" << endl;
	wcout << L"I::::::::In::::n    n::::n  c:::::::::::::::::c i::::::i  d:::::::::::::::::d e::::::::eeeeeeee    n::::n    n::::n      tt::::::::::::::t" << endl;
	wcout << L"I::::::::In::::n    n::::n   cc:::::::::::::::c i::::::i   d:::::::::ddd::::d  ee:::::::::::::e    n::::n    n::::n        tt:::::::::::tt" << endl;
	wcout << L"IIIIIIIIIInnnnnn    nnnnnn     cccccccccccccccc iiiiiiii    ddddddddd   ddddd    eeeeeeeeeeeeee    nnnnnn    nnnnnn          ttttttttttt" << endl;
	int curmode = _setmode(_fileno(stdout), prevmode);
}

void StoryRender()
{
	system("cls");
	cout << "���ѷα�" << endl;
	cout << endl;
	cout << "������ ���ΰ��� �ֱ� ���λ���� �߻��Ͽ��ٴ� ��� ���� ������ �̵��ϰ� �ȴ�." << endl;			 
	cout << "�����ϰ� ���ΰ��� ���� �ֹε�� �̾߱��ϴٰ� ���λ���� �߻��� �ǹ� ���縦 ���� �� �ǹ� ����." << endl;
	cout << "������ �װ����� �°� ���ڿ����� ������ �Ͼ��." << endl;
	cout << "���� ���ΰ��� ���縦 ���� �� ����� �ذ��� �� ������?" << endl;
	Sleep(200);
	while (1)
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
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 6;
	int y = Resolution.Y / 2.5;
	int originy = y;
	Gotoxy(x, y);
	cout << "ó������" << endl;
	Gotoxy(x, y + 1);
	cout << "���丮����" << endl;
	Gotoxy(x, y + 2);
	cout << "����" << endl;
	Gotoxy(x, y + 3);
	cout << "��������" << endl;
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
			if (y < originy + 3)
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
				return MENU::SAVE;
			else if (originy + 3 == y)
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
		case MENU::SAVE:
			return false;
		case MENU::QUIT:
			return false;
		}
	}
}