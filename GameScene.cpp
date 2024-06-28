#include "GameScene.h"
#include "stringExtension.h"

void Render()
{
	int screenWidth;
	FullScreen();
	screenWidth = DrawGamePanel();
	CursorVis(false, 1);


	std::vector<std::string> talkVec = ReadTalkTextFile("TalkText/TalkText.txt");
	int currentTalkIndex = 0;

	while (currentTalkIndex < talkVec.size())
	{
		//파일 로드
		std::vector<std::string> ret = splitString(talkVec[currentTalkIndex], ',');
		std::string nameText = ret[0];
		std::string talkText = ret[1];
		std::string imageText = ret[2];

		std::vector<std::string> characterText = ReadFileForVector("Character/" + imageText + ".txt");
		int middlePos = (screenWidth - characterText[0].length())/2;
		for (size_t i = 0; i < characterText.size(); ++i)
		{
			GotoPos(middlePos, 10 + i);
			std::cout << characterText[i];
			
		}
		Sleep(1000);

		int currentCharIndex = 0;
		int currentAllCharIndex = 0;
		GotoPos(5, 66);
		std::cout << nameText;
		int posY = 71;
		while (talkText.size() > currentAllCharIndex)
		{
			GotoPos(10 + currentCharIndex * 2, posY);
			if (talkText[currentAllCharIndex] == '|')
			{
				Sleep(100);
			}
			else if (talkText[currentAllCharIndex] == '\\')
			{
				currentCharIndex = -2;
				posY+=2;
			}
			else
			{
				std::cout << talkText[currentAllCharIndex];
			}
			++currentCharIndex;
			++currentAllCharIndex;
			Sleep(20);
		}

		while (1)
		{
			if (_kbhit() > 0)
			{
				int nKey;
				nKey = _getch();
				if (_getch() == 32 || _getch() == 13)
				{
					break;
				}
			}
		}

		++currentTalkIndex;;

		//기존 글자 없애기
		system("cls");
		DrawGamePanel();
	}
}