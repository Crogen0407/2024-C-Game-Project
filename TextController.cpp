#include "TextController.h"
#include "console.h"

void RenderTalkText(std::string talkText)
{
	int currentCharIndex = 0;
	int currentAllCharIndex = 0;
	
	int posY = 71;
	while (talkText.size() > currentAllCharIndex)
	{
		Gotoxy(10 + currentCharIndex * 2, posY);
		if (talkText[currentAllCharIndex] == '|')
		{
			Sleep(100);
		}
		else if (talkText[currentAllCharIndex] == '\\')
		{
			currentCharIndex = -2;
			posY += 2;
		}
		else
		{
			std::cout << talkText[currentAllCharIndex];
		}
		++currentCharIndex;
		++currentAllCharIndex;
		Sleep(20);
	}
}

void RenderNameText(std::string nameText)
{
	Gotoxy(5, 66);
	std::cout << nameText;
}
