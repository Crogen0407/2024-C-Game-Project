#include <Windows.h>
#include <conio.h>
#include "UIManager.h"
#include "GameData.h"
#include "console.h"

int main()
{
	FullScreen();
	DrawGamePanel();

	std::vector<std::string> talkVec = ReadTalkTextFile("TalkText/TalkText.txt");
	int currentTalkIndex = 0;

	while (currentTalkIndex < talkVec.size())
	{
		Sleep(1000);
		std::string temp = talkVec[currentTalkIndex];
		int currentCharIndex = 0;
		while (temp.size() > currentCharIndex)
		{
			GotoPos(10 * currentCharIndex, -100);
			if (temp[currentCharIndex] == '\\')
			{
				Sleep(100);
			}
			else
			{
				std::cout << temp[currentCharIndex];
			}
			++currentCharIndex;
			Sleep(50);
		}

		/*while(1)
		{
			if (std::_getch())
			{
				Sleep(1000);
				break;
			}
		}*/

		++currentTalkIndex;;

		//기존 글자 없애기
		system("cls");
		DrawGamePanel();
	}
}